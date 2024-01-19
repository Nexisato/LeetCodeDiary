# @Date: 2024-01-19 11:00:34
 # @Author: nexisato
 # @FilePath: /LeetCodeDiary/scripts/format.sh
 # @Description
### 


# delete all *.out/*.exe files
WORK_DIR=$1
find . -name "*.out" -type f -delete
delete_files() {
    find ${WORK_DIR} -type f \(-name "*.exe" -o -name "*.out" \) -exec rm -f {} \;
}