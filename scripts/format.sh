#!/bin/bash
###
 # @Date: 2024-01-19 11:00:34
 # @Author: nexisato
 # @FilePath: /LeetCodeDiary/scripts/format.sh
 # @Description: 删除 *.exe 和 *.out 等二进制文件，并格式化目录
 # @usage ./scripts/format.sh ${WORK_DIR} ${COMMAND}
 #   ${WORK_DIR} 为工作目录
 #   ${COMMAND} 为命令，可选值为 [delete_bin/format_name]
### 

WORK_DIR=$1

# 检查是否提供了工作目录
if [ -z "$WORK_DIR" ]; then
    echo "Error: No directory provided."
    exit 1
fi

function delete_bin() {
    find "${WORK_DIR}" -name '*.exe' -type f -print -exec rm -f {} \;
    find "${WORK_DIR}" -name '*.out' -type f -print -exec rm -f {} \;
}

# 格式化目录文件，将 '_ '改为 '-'
function format_name() {
    # 首先重命名文件, *.json 文件不重命名   
    find "${WORK_DIR}" -type f -name '*_*' -not -name '*.json'| while read fname; do
        newname=$(echo "${fname}" | tr '_' '-')
        if [ "${fname}" != "${newname}" ] && [ ! -e "${newname}" ]; then
            mv -v "${fname}" "${newname}"
        fi
    done

    # 然后重命名目录
    find "${WORK_DIR}" -type d -name '*_*' | while read dname; do
        newdname=$(echo "${dname}" | tr '_' '-')
        if [ "${dname}" != "${newdname}" ] && [ ! -e "${newdname}" ]; then
            mv -v "${dname}" "${newdname}"
        fi
    done
}

# 执行命令
if [ "$2" = "delete_bin" ]; then
    delete_bin
elif [ "$2" = "format_name" ]; then
    format_name
else
    echo "Error: Unknown command or no command provided."
    exit 1
fi
