require "readline"
require "file_system"
require "http/client"
require "figlet"

# Clear the console
system("clear")

# Print the ASCII art
puts Figlet.text("E x a m p l e")
puts "(c) Copyright AUTHOR. All rights reserved.\n"

def clear_screen
  system("clear")
end

def open_license
  puts "\n[CLI]: Opening LICENSE\n"
  spawn "xdg-open https://example.com/license"
end

def list_directory(current_dir : String)
  begin
    files = Dir.entries(current_dir)
    puts "\n[CLI]: Directory listing for #{current_dir}:\n"
    files.each do |file|
      puts file
    end
  rescue
    puts "\n[CLI]: An error occurred while listing the directory\n"
  end
end

def main
  clear_screen
  current_dir = "/home/#{ENV["USER"]}"

  while true
    print "#{ENV["USER"]}@CLI ~ $ "
    command = Readline.readline.chomp

    if command.empty? || command.starts_with?(" ")
      next
    elsif command.starts_with?("cls") || command.starts_with?("clear")
      clear_screen
    elsif command.starts_with?("license")
      open_license
    elsif command.starts_with?("authors")
      puts "\n[CLI]: (c) Copyright AUTHOR. All rights reserved.\n"
    elsif command.starts_with?("cd")
      new_dir = command.split(" ")[1]
      begin
        Dir.chdir(new_dir)
        current_dir = Dir.pwd
        puts "\n[CLI]: Changed directory to #{current_dir}\n"
      rescue
        puts "\n[CLI]: Directory not found: #{new_dir}\n"
      end
    elsif command.starts_with?("dir") || command.starts_with?("ls")
      list_directory(current_dir)
    elsif command.starts_with?("exit") || command.starts_with?("quit")
      puts "\n[CLI]: Exiting"
      break
    else
      puts "\n[CLI]: '#{command.split(" ")[0]}' is not recognized as an internal or external command, operable program or batch file.\n"
    end
  end
end

main
