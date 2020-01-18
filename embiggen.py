import sys

file = sys.argv[1]
file_lines = open(file).read().split('\n')
for line in file_lines:
    if line[0:2] == "v ":
        line_tokens = line.split(' ')
        x = float(line_tokens[1])
        y = float(line_tokens[2])
        z = float(line_tokens[3])
        print(f"v {x*100} {y*100} {z*100}")
    elif line[0:2] == "f " and '/' in line:
        line_tokens = line.split(' ')
        num0 = int(line_tokens[1].split('/')[0])
        num1 = int(line_tokens[2].split('/')[0])
        num2 = int(line_tokens[3].split('/')[0])
        print(f"f {num0} {num1} {num2}")
    else:
        print(line)