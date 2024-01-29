from setuptools import find_packages, setup

package_name = 'redshift_odometry'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
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
            'redshift_odometry = redshift_odometry.redshift_odometry:main'
        ],
    },
)
