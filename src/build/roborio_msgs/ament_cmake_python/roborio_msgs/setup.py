from setuptools import find_packages
from setuptools import setup

setup(
    name='roborio_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('roborio_msgs', 'roborio_msgs.*')),
)
