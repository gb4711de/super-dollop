#!/usr/bin/env python3
"""
Example script demonstrating the unit converter CLI tool
Run this after installing the package with: pip install -e .
"""
import subprocess
import sys


def run_command(cmd):
    """Run a command and print the output"""
    print(f"\n$ {cmd}")
    result = subprocess.run(cmd, shell=True, capture_output=True, text=True)
    print(result.stdout, end='')
    if result.stderr:
        print(result.stderr, end='')
    return result.returncode


def main():
    """Run example conversions"""
    print("=" * 60)
    print("Unit Converter CLI Tool - Examples")
    print("=" * 60)
    
    examples = [
        "convert list-conversions",
        "convert convert 100 km miles",
        "convert convert 10 miles km",
        "convert convert 25 celsius fahrenheit",
        "convert convert 98.6 fahrenheit celsius",
        "convert convert 0 celsius kelvin",
        "convert convert 70 kg lbs",
        "convert convert 16 oz kg",
        "convert convert 5 meters feet",
    ]
    
    for cmd in examples:
        run_command(cmd)
    
    print("\n" + "=" * 60)
    print("For more help, run: convert --help")
    print("=" * 60)


if __name__ == "__main__":
    main()
