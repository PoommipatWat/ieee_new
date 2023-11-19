from setuptools import setup

import os
from glob import glob


package_name = 'ieee_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name), glob("launch/*launch.py")),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='poom',
    maintainer_email='poommipat_wat@cmu.ac.th',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "imu_node = ieee_pkg.imu:main",
            "camera_node = ieee_pkg.camera:main",
            "control_node = ieee_pkg.control:main",
            "robot_core_node = ieee_pkg.robot_core:main",
        ],
    },
)
