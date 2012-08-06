import config
import fileinput
import os

rootdir = '..'

# we do a recursive walk 
for path, dirs, files in os.walk(rootdir):
    if files:
        for file in files:
            fullPathFile  = os.path.join(path,file)
            # in all the files we search and replace for the placeholders
            for line in fileinput.FileInput(fullPathFile,inplace=1):
                for find,replace in config.REPLACEMENT.items():
                    line  = line.replace(find,replace)
                #note FileInput redirect STDIN to the file that's why
                # we use print and nothing is displayed
                print(line)



