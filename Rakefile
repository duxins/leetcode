#
# Xin Du
# 
# Inspired by https://github.com/lexrus/LeetCode.swift/blob/master/Rakefile
#

require 'nokogiri'
require 'open-uri'

task :sync do
  doc = Nokogiri::HTML(open("https://leetcode.com/problemset/algorithms/"))
  problems = doc.css('#problemList tbody tr')

  problems = problems.map do |tr|
    id = tr.at('td:nth-child(2)').text.rjust(3, '0')
    a = tr.at('td:nth-child(3) a')
    href = a.attributes['href'].text
    title = a.text
    locked = tr.at('td:nth-child(3) i').nil? ? false : true
    difficulty =  tr.at('td:last').text

    target = id + '-' + href.split('/').last
    source_file = File.expand_path("../#{target}.cpp", __FILE__)

    finished = File.exists?(source_file)

    "| #{finished ? '✅' : ' '} " << 
    "| #{id} " <<
    "| [#{title}](https://leetcode.com#{href}) " << (locked ? "🔒 " : " ") <<
    "| "  << (finished ? "[Source](./#{target}.cpp) " : " ") << 
    "| "

  end

  readme_file = File.expand_path("../README.md", __FILE__)

  table = "|   |  #  | Title | Souce |\n" << 
          "|---|-----|-------|-------|\n" << problems.reverse.join("\n")

  readme = File.read(readme_file).gsub(/\[\/\/\]: # \(PROBLEMS BEGIN\)(.*)\[\/\/\]: # \(PROBLEMS END\)/m, "[//]: # (PROBLEMS BEGIN)\n\n#{table}\n\n[//]: # (PROBLEMS END)")

  File.write(readme_file, readme)

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

  code = (<<-EOT)
#{comment}    

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

  return 0;
}
  EOT

  File.write(source_file, code)

  cmake_file = File.expand_path('../CMakeLists.txt', __FILE__)
  File.open(cmake_file, 'a') do |file|
    file.write("target(#{target})")
  end

  $stderr.puts 'Done'

end

