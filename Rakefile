#
# Xin Du
# 
# Inspired by https://github.com/lexrus/LeetCode.swift/blob/master/Rakefile
#

require 'open-uri'
require 'net/http'
require 'json'
require 'nokogiri'
require 'pathname'

task :sync do
  url = "https://leetcode.com/api/problems/algorithms/"
  doc = Net::HTTP.get(URI.parse(url))
  json = JSON.parse(doc)

  pairs = json['stat_status_pairs']

  problems = pairs.map do |pair|
    stat = pair['stat']
    locked = pair['paid_only']
    level = pair['difficulty']['level']

    id = stat['question_id'].to_s.rjust(3, '0')
    slug = stat['question__title_slug'] 
    title = stat['question__title']
    difficulty = {1 => 'Easy', 2 => 'Medium', 3=>'Hard'}[level]

    target = id.to_s + '-' + slug
    source_file = File.expand_path("../#{target}.cpp", __FILE__)
    finished = File.exists?(source_file)

    "| #{finished ? '✅' : ' '} " << 
    "| #{id} " <<
    "| [#{title}](https://leetcode.com/problems/#{slug}/) " << (locked ? "🔒 " : " ") <<
    "| "  << (finished ? "[Source](./#{target}.cpp) " : " ") << 
    "| #{difficulty} " << 
    "| "

  end


  readme_file = File.expand_path("../README.md", __FILE__)

  total = problems.count
  finished = problems.count {|p| p.match(/✅/) }
  badge = "![Progress](https://img.shields.io/badge/Progress-#{finished}%2F#{total}-blue.svg)"

  table = "|   |  #  | Title | Source |  Difficulty |\n" << 
          "|---|-----|-------|-------|-------------|\n" << problems.reverse.join("\n")

  readme = File.read(readme_file).gsub(/\[\/\/\]: # \(PROBLEMS BEGIN\)(.*)\[\/\/\]: # \(PROBLEMS END\)/m, "[//]: # (PROBLEMS BEGIN)\n\n#{table}\n\n[//]: # (PROBLEMS END)")
  readme = readme.gsub(/^!\[Progress\].*$/, badge)

  File.write(readme_file, readme)

end

task :practice do
  readme_file = File.expand_path("../README.md", __FILE__)
  files = File.read(readme_file).scan(/\[Source\]\(([^)]+)\)/)

  # Pick a random problem
  source_file = files.sample(1).first.first

  print "Problem ID: "
  id = $stdin.readline.chop.rjust(3, '0')

  source_file = files.find{|m| m.first =~ Regexp.new("#{id}-") }.to_a.first unless id == '000'

  raise('Source file not found') if source_file.nil?

  source = File.read(source_file)

  source.sub!(/class Solution(.*)^};/m) do |m| 
    # Remove private methods
    m = m.gsub(/private:(.*)^public:/m, 'public:')
    # Remove method body
    m.gsub(/^\s{6,}.*\n/, '')
  end

  practice_file = File.expand_path("../000-practice.cpp", __FILE__)
  File.write(practice_file, source)

  %x(which clion && clion ./000-practice.cpp)

end


task :start do
  print "Problem ID: "
  id = $stdin.readline.chop.rjust(3, '0')
  next if id.empty?

  readme_file = File.expand_path("../README.md", __FILE__)
  readme = File.read(readme_file)

  problem = readme.match(/\| (#{id}) \| \[([^\]]+)\]\(([^\)]+)\)/) do |m|
    {
      title: m[2],
      href: m[3]
    }
  end

  $stderr.puts "-" * 80

  if problem.nil?
    $stderr.puts("Problem not found")
    next
  end

  href = problem[:href]
  target = id + '-' + href.split('/').last
  source_file = File.expand_path("../#{target}.cpp", __FILE__)
  $stderr.puts("Source file: #{source_file}")
  if File.exists?(source_file)
    $stderr.puts("Source file exists.")
    next
  end

  doc = Nokogiri::HTML(open(href))

  #Title
  title = doc.at('.question-title h3')
  next if title.nil?
  title = title.text

  #Problem content
  content = doc.at('.question-content')
  next if content.nil?

  #Tags
  tags_node = content.at('#tags')
  tags = []
  if tags_node
    tags_node.parent.css('span a').each do |a|
      tags << a.text
    end
    tags_node.parent.remove
  end

  #Similar questions
  similar_node = content.at('#similar')
  similar_node.parent.remove unless similar_node.nil?

  comment = "#{title}\n\n"
  comment += content.text.strip.gsub(/(\n\s+)+/m, "\n")
  comment << "\n\nTags: #{tags.join(', ')}\n" if tags.count > 0
  comment << "\n#{href}"

  comment = comment.gsub(/^/, "//  ")

  test_name = "leetcode_#{target.gsub(/-/, '_')}"

  code = (<<-EOT)
#{comment}    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;


TEST(#{test_name}, Basic)
{

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
  EOT


  File.write(source_file, code)

  cmake_file = File.expand_path('../CMakeLists.txt', __FILE__)
  File.open(cmake_file, 'a') do |file|
    file.write("target(#{target})\n")
  end

  configuration_file = File.expand_path("../.idea/runConfigurations/#{target.gsub(/-/,'_')}.xml", __FILE__)

  unless File.exists? (configuration_file)

    configuration = (<<-EOT)
<component name="ProjectRunConfigurationManager">
  <configuration default="false" name="#{target}" type="CMakeGoogleTestRunConfigurationType" factoryName="Google Test" WORKING_DIR="" PASS_PARENT_ENVS_2="false" PROJECT_NAME="leetcode" TARGET_NAME="#{target}" CONFIG_NAME="Debug" RUN_TARGET_PROJECT_NAME="leetcode" RUN_TARGET_NAME="#{target}" TEST_MODE="SUITE_TEST">
    <envs />
    <method />
  </configuration>
</component>
    EOT

    configuration.chomp!

    File.write(configuration_file, configuration)

  end

  $stderr.puts 'Done'

end

task :update_config do
  Pathname('.idea/runConfigurations').expand_path.find do |path|
    if path.file? && path.basename.to_s =~ /.xml/
      content = File.read(path)
      content.gsub!('type="CMakeRunConfiguration"', 'type="CMakeGoogleTestRunConfigurationType"')
      content.gsub!('factoryName="Application"', 'factoryName="Google Test"')
      content.gsub!(/RUN_TARGET_NAME="(.*?)">/, 'RUN_TARGET_NAME="\1" TEST_MODE="SUITE_TEST">')
      File.write(path, content)
    end
  end
end
