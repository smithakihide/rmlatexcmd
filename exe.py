import subprocess
import sys
import os

print("start a process v12")


print(sys.argv)
#compile latex
if len(sys.argv) < 2:
    quit()

is_clean = False
is_uncomment = False
is_first = True
input_path = ""
for s in sys.argv:
    if s == "--clean":
        is_clean = True
    elif input_path == "" and not is_first:
        input_path = s
    elif s == "--uncomment":
        is_uncomment = True

    is_first = False

if input_path == "":
    print("there is no input file")
    quit()

name,ext = os.path.splitext(input_path)

if is_clean:
    print("clean the all temporary files created by platex")
    for ex in [".aux", ".toc", ".log", ".dvi"]:
        try:
            os.remove(name + ex)
        except OSError:
            pass

p1 = subprocess.call(["platex", name + ".tex"])
p1 = subprocess.call(["platex", name + ".tex"])
p1 = subprocess.call(["platex", name + ".tex"])
p1 = subprocess.call(["dvipdfm", name + ".dvi"])

print("finished")