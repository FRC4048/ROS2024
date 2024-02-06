from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'redshift_odometry'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*launch.[pxy][yma]*'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='redshift',
    maintainer_email='sushant.santhosh26@gmail.com',
    description='FRC 2024 odometry',
    license='BSD',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'redshift_odometry = redshift_odometry.redshift_odometry:main',
            'redshift_inverse = redshift_odometry.redshift_inverse:main'
        ],
    },
)
