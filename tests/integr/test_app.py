#!/usr/bin/env python3

import logging
from subprocess import PIPE, Popen

def test_base_options():
    command = "/home/ilya0100/documents/MultiThreadCPP/UniqueNames/build/app/demo_app"
    logging.debug(f'Run command {command}')
    
    p = Popen(command, stdout=PIPE, stderr=PIPE, stdin=PIPE)

    p.stdin.write(b"1\n")
    p.stdin.flush()
    id = p.stdout.readline().decode("utf-8").strip()
    
    p.stdin.write(f"4 {id}\n".encode("utf-8"))
    p.stdin.flush()
    _ = p.stdout.readline().decode("utf-8").strip()

    p.stdin.write(f"2 {id} new_name\n".encode("utf-8"))
    p.stdin.flush()

    p.stdin.write(f"3 {id}\n".encode("utf-8"))
    p.stdin.flush()
    output, errors = p.communicate(b'5')

    if p.returncode or errors or output:
        raise IOError(f"CMD = [{command}]\nErrors: {errors}\nOutput: {output}")

    p.wait()


print("====Running integration tests====")

print("Test: base options")
test_base_options()
print("OK")
print("=" * 33)
