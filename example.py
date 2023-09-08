import pyfiglet
import os
from datetime import datetime
import webbrowser
import requests
import time
import clipboard
import requests
from rich import print
from rich.markdown import Markdown
from rich.rule import Rule

os.system("cls" if os.name == "nt" else "clear")

current_dir = f"C:\\Users\\{os.getenv('USERNAME')}"
os.chdir(current_dir)

print(pyfiglet.figlet_format(str("E x a m p l e")))
print("(c) Copyright AUTHOR. All rights reserved.\n")

while True:
    try:
        if current_dir == f"C:\\Users\\{os.getenv('USERNAME')}" or current_dir == f"~\\{os.getenv('USERNAME')}":
            command = input(f"{os.getenv('USERNAME')}@CLI ~ $ ")
        else:
            command = input(f"{os.getenv('USERNAME')}@CLI {current_dir} $ ")

        if command.startswith(" ") or len(command) == 0:
            continue

        elif command.startswith("cls") or command.startswith("clear"):
            os.system("cls" if os.name == "nt" else "clear")
            
        elif command.startswith("license"):
            print("\n[CLI]: Opening LICENSE\n")
            webbrowser.open("https://example.com/license")

        elif command.startswith("authors"):
            print(f"\n[CLI]: (c) Copyright AUTHOR. All rights reserved.\n")
        
        elif command.startswith("cd"):
            new_dir = command.split(" ", 1)[1]
            try:
                os.chdir(new_dir)
                current_dir = os.getcwd()
                print(f"\n[CLI]: Changed directory to {current_dir}\n")
            except FileNotFoundError:
                print(f"\n[CLI]: Directory not found: {new_dir}\n")

        elif command.startswith("dir") or command.startswith("ls"):
            os.system("dir" if os.name == "nt" else "ls")
        
        elif command.startswith("exit") or command.startswith("quit"):
            print("\n[CLI]: Exiting")
            os._exit(0)

        elif command.startswith("dir") or command.startswith("ls"):
            print("\n")
            os.system("dir" if os.name == "nt" else "ls")
            print("\n")

        elif command.startswith("cmd"):
            os.system("cmd")

        elif command.startswith("powershell"):
            os.system("powershell")
        
        else:
            print(f"\n[CLI]: '{command.split()[0]}' is not recognized as an internal or external command, operable program or batch file.\n")

    except KeyboardInterrupt:
        print("\n")
        continue
    
    except Exception as f:
        print(f"\n[CLI]: An error has occured: \n{f}\n")
