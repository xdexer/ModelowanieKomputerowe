from distutils.core import setup
import py2app

setup(
    app=["anim_array.py"],
    setup_requires=["py2app"],
)