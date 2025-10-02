from setuptools import setup, find_packages

setup(
    name='unit-converter-cli',
    version='0.1.0',
    description='A CLI tool for converting between different units',
    author='Your Name',
    packages=find_packages(),
    install_requires=[
        'click>=8.0.0',
    ],
    entry_points={
        'console_scripts': [
            'convert=unit_converter.cli:main',
        ],
    },
    python_requires='>=3.7',
)
