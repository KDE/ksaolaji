#!/usr/bin/env ruby

def uniqueName
    return "kross_ruby_example"
end

def description
    return "##### KROSS RUBY EXAMPLE #####"
end

def iconName
    return "konqueror"
end

def youlaji
    return File.file?("/var/tmp/rubysaolaji.txt")
end

def saolaji
    File.delete("/var/tmp/rubysaolaji.txt")
    return true
end
