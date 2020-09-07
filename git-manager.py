#!/usr/bin/env python

import os
import sys
import subprocess

# Display the usage of the program
def display_usage():
    print("usage: git-manager [-h | --help] <login> <repository-path>\n"\
          "Clone all files from blih and keep them updated.\n\n"\
          "     -h | --help     :  display this help."\
          "     -u | --update   :  update all repositories in <repository-path>.")


# Execute the compilation command to reload object files.
def execute_command_and_get_output(commandline):

    # Executing command.
    process = subprocess.Popen(commandline, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    # Run while the command didn't end.
    while True:
        
        # Reading return code.
        output = process.stderr.readline()
        if len(output):
            print(f"Error: {output.strip()}")
            exit(1)
        returncode = process.poll()

        # Process has finished        
        if returncode is not None:
            if returncode:
                print(f"Return code: {returncode}")
                exit(1)
            else:
                return (process.stdout.readlines())

        return ""

def execute_git_command(commandline):

    # Executing command.
    process = subprocess.Popen(commandline, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    # Run while the command didn't end.
    while True:

        returncode = process.poll()

        output = process.stdout.readline()
        if len(output):
            print(output)

        # Process has finished        
        if returncode is not None:
            if returncode:
                output = process.stderr.readlines()
                print(f"Return code: {returncode}, error:  {output}")
                exit(returncode)
            return

# Updates all repositories at the <repository-path> argument.
def update_all_repositories(path):
    
    ## Getting a list of all repositories already cloned.
    repositories = [d for d in os.listdir(path) if os.path.isdir(os.path.join(path, d))]    

    for repo in repositories:
        execute_command_and_get_output(["git", "pull", path + "/" + repo])

# Download all repositories from blih.   
def download_all_blih_repository():

    ## Getting the list of repositories.
    res = execute_command_and_get_output(["blih", "-u", sys.argv[1], "repository", "list"])
    repo_list = [i[:-1] for i in res]

    ## Cloning ...
    for repo in repo_list:
        repo = repo.decode("utf-8")
        print(f"Cloning repo: {str(repo)}")
        execute_git_command(["git", "clone", "git@git.epitech.eu:/" + sys.argv[1]  + "/" + repo, sys.argv[2] + "/" + repo])

# Main function
def main():

    ## check arguments
    if len(sys.argv) == 2 and sys.argv[1] == "-h":
          display_usage()
          exit(0)
    if len(sys.argv) != 3 and len(sys.argv) != 4:
          print("Error, there isn't a valid number of arguments.\n", file=sys.stderr)
          display_usage()
          exit(1)
    
    ## Options
    if len(sys.argv) == 4 and (sys.argv[1] == '-u' or sys.argv[1] == '--update'):
        update_all_repositories(sys.argv[3])
    else:
        download_all_blih_repository()

if __name__ == "__main__":
    main()
