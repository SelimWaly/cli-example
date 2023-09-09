import * as readline from 'readline';
import * as fs from 'fs';
import * as child_process from 'child_process';

// Clear the console
console.clear();

// Print the ASCII art
console.log("E x a m p l e");
console.log("(c) Copyright AUTHOR. All rights reserved.\n");

function clearScreen() {
  console.clear();
}

function openLicense() {
  console.log("\n[CLI]: Opening LICENSE\n");
  child_process.exec('xdg-open https://example.com/license');
}

function listDirectory(currentDir: string) {
  try {
    const files = fs.readdirSync(currentDir);
    console.log(`\n[CLI]: Directory listing for ${currentDir}:\n`);
    files.forEach((file) => {
      console.log(file);
    });
  } catch (error) {
    console.log("\n[CLI]: An error occurred while listing the directory\n");
  }
}

function main() {
  clearScreen();
  let currentDir = `/home/${process.env.USER}`;

  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });

  rl.prompt();

  rl.on('line', (line) => {
    const command = line.trim();

    if (command === "") {
      rl.prompt();
      return;
    }

    if (command.startsWith("cls") || command.startsWith("clear")) {
      clearScreen();
    } else if (command.startsWith("license")) {
      openLicense();
    } else if (command.startsWith("authors")) {
      console.log(`\n[CLI]: (c) Copyright AUTHOR. All rights reserved.\n`);
    } else if (command.startsWith("cd")) {
      const newDir = command.split(" ")[1];
      try {
        process.chdir(newDir);
        currentDir = process.cwd();
        console.log(`\n[CLI]: Changed directory to ${currentDir}\n`);
      } catch (error) {
        console.log(`\n[CLI]: Directory not found: ${newDir}\n`);
      }
    } else if (command.startsWith("dir") || command.startsWith("ls")) {
      listDirectory(currentDir);
    } else if (command.startsWith("exit") || command.startsWith("quit")) {
      console.log("\n[CLI]: Exiting");
      rl.close();
    } else {
      console.log(`\n[CLI]: '${command.split(" ")[0]}' is not recognized as an internal or external command, operable program or batch file.\n`);
    }

    rl.prompt();
  });
}

main();
