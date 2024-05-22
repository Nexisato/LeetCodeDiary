# Define the source directories based on the operating system
PREFIX_DIR = .vscode-settings

ifeq ($(shell uname),Linux)
  SOURCE_DIR = $(PREFIX_DIR)/linux
else ifeq ($(shell uname),Darwin)
  SOURCE_DIR = $(PREFIX_DIR)/macOS
else
  $(error Unsupported operating system)
endif

# Define the target directory
TARGET_DIR = .vscode

config:
	mkdir -p $(TARGET_DIR)
	rm -rf $(TARGET_DIR)/*
	cp -r $(SOURCE_DIR)/. $(TARGET_DIR)/

.PHONY: config


# 定义工作目录，默认为当前目录
WORK_DIR ?= .

# 定义shell命令
FORMAT_CMD = ./scripts/format.sh $(WORK_DIR) format_name
DELBIN_CMD = ./scripts/format.sh $(WORK_DIR) delete_bin

# 定义规范化目标
normal:
	chmod +x ./scripts/format.sh
	$(FORMAT_CMD)

.PHONY: normal


delbin:
	chmod +x ./scripts/format.sh
	$(DELBIN_CMD)

.PHONY: delbin
