import os

def main():
    path = "./LeetCode/"
    dirRename(path)

def dirRename(path):
    fileList = os.listdir(path)
    for s in fileList:
        old_name = s
        oldNameList = s.split('_')
        oldNameList[0] = oldNameList[0].rjust(4, '0')
        new_name = "_".join(oldNameList)

        os.rename(os.path.join(path, old_name), os.path.join(path, new_name))



if __name__ == '__main__':
    main()