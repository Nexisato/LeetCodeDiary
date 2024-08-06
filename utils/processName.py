import os
from typing import List
import click
from loguru import logger

CMD_NAME = "format-rename"


@click.command(name=CMD_NAME)
@click.option(
    "-p",
    "--path",
    type=str,
    default="./LeetCode",
    required=False,
    help="[Option] path to format name, default './LeetCode'",
)
def exec_format_rename(path: str) -> None:
    file_names: List[str] = os.listdir(path)
    for file_name in file_names:
        name_list: List[str] = file_name.split("_")
        name_list[0] = name_list[0].rjust(4, "0")
        new_name = "_".join(name_list)
        os.rename(os.path.join(path, file_name), os.path.join(path, new_name))
    logger.info(f"[Done] {len(file_names)} formatted.")


if __name__ == "__main__":
    exec_format_rename()
