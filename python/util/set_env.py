import platform
import subprocess
import sys
import DoraemonPocket


def get_sys_env():
    """collect environment information"""
    env_info = {}
    env_info['platform'] = platform.platform()
    env_info['Python'] = sys.version.replace('\n', '')

    try:
        gcc = subprocess.check_output(['gcc', '--version']).decode()
        gcc = gcc.strip().split('\n')[0]
        env_info['GCC'] = gcc
    except:
        pass

    env_info['DoraemonPocket'] = DoraemonPocket.__version__

    return env_info