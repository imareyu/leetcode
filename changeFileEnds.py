import os

dir_path = 'D:/leetcode/githubUpdate/'

for root, dirs, files in os.walk(dir_path):
    if root.count('.git') == 0:#.git文件不要动
        for file in files:
            if file.endswith('.txt'):
                file_path = os.path.join(root, file);
                new_file_path = os.path.splitext(file_path)[0]+'.cpp'
                print(file_path)
                print(new_file_path)
                os.rename(file_path, new_file_path)
