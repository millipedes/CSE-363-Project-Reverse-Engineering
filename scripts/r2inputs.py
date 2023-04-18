import argparse

parser = argparse.ArgumentParser(description='file to copy')
parser.add_argument('-f', '--file', type=str, help='Path to the file')
args = parser.parse_args()

def main():
    try:
        file_name = args.file
        file_name = file_name.replace('.txt', '.out')
        with open(file_name, 'w') as out_file:
            out_file.write('aaa\n')
            with open(args.file, 'r') as in_file:
                line = in_file.readline()
                while line:
                    line = 's sym.' + line
                    out_file.write(line)
                    out_file.write('pdg\n')
                    line = in_file.readline()
    except FileNotFoundError:
        print('File', args.file, 'Not found')

if __name__ == '__main__':
    main()
