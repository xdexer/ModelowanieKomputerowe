from distutils.core import setup
import py2app

setup(
    app=["gameoflife.py"],
    setup_requires=["py2app"],
)