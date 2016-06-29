from distutils.core import setup, Extension

module1 = Extension('friend',
                    define_macros = [('PYMESH_EXPORTS', '1')],
                    sources = ['main.c'])

setup(
          name='friend',
          version='1.0.0',
          description = 'This is a friends package',
          ext_modules=[module1],
     )