#!/usr/bin/env python3

import logging
from subprocess import PIPE, Popen

def test_base_options():
    command = "./build/app/demo_app"
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


def test_wrong_id():
    command = "./build/app/demo_app"
    logging.debug(f'Run command {command}')

    p = Popen(command, stdout=PIPE, stderr=PIPE, stdin=PIPE)

    p.stdin.write(b"1\n")
    p.stdin.flush()
    _ = p.stdout.readline().decode("utf-8").strip()

    output, errors = p.communicate(b"2 123 name 3 234 4 345 5")
    if p.returncode or output:
        raise IOError(f"CMD = [{command}]\nOutput: {output}")

    errors = errors.decode("utf-8").strip().split('\n')
    if len(errors) != 3:
        raise IOError(f"Errors count: {len(errors)} != 3")

print("====Running integration tests====")

print("Test: base options")
test_base_options()
print("OK")

print("Test: wrong id")
test_wrong_id()
print("OK")

print("=" * 33)
