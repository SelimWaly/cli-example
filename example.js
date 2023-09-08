const readline = require('readline');
const fs = require('fs');
const https = require('https');
const figlet = require('figlet');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

console.clear();

console.log(figlet.textSync('E x a m p l e'));
console.log('(c) Copyright Voltra Inc. All rights reserved.\n');

function promptUser() {
  rl.question(`${process.env.USERNAME}@CLI ~ $ `, (command) => {
    if (command.startsWith(' ') || command.length === 0) {
      promptUser();
    } else if (command.startsWith('cls') || command.startsWith('clear')) {
      console.clear();
      promptUser();
    } else if (command.startsWith('license')) {
      console.log('\n[CLI]: Opening LICENSE\n');
      window.location.href = 'https://example.com/license'
      promptUser();
    } else if (command.startsWith('authors')) {
      console.log(`\n[CLI]: (c) Copyright AUTHOR. All rights reserved.\n`);
      promptUser();
    } else if (command.startsWith('cd')) {
      const newDir = command.split(' ')[1];
      try {
        process.chdir(newDir);
        console.log(`\n[CLI]: Changed directory to ${process.cwd()}\n`);
        promptUser();
      } catch (error) {
        console.log(`\n[CLI]: Directory not found: ${newDir}\n`);
        promptUser();
      }
    } else if (command.startsWith('dir') || command.startsWith('ls')) {
      const currentDir = process.cwd();
      fs.readdir(currentDir, (err, files) => {
        if (err) {
          console.error(`\n[CLI]: An error occurred while listing the directory: ${err}\n`);
        } else {
          console.log(`\n[CLI]: Directory listing for ${currentDir}:\n`);
          files.forEach((file) => {
            console.log(file);
          });
        }
        promptUser();
      });
      promptUser();
    } else if (command.startsWith('exit') || command.startsWith('quit')) {
      console.log('\n[CLI]: Exiting');
      rl.close();
    } else {
      console.log(`\n[CLI]: '${command.split(' ')[0]}' is not recognized as an internal or external command, operable program or batch file.\n`);
      promptUser();
    }
  });
}

promptUser();
