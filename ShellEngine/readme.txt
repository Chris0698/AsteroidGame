To compile the engine, you need to:

1 Find, download and install Microsoft DirectX SDK June 2010
2 Run Visual Studio 2015.
3 Create a Windows project. This should be EMPTY.
4 Move all .cpp and .h files from Shell2020 to the project folder. 
  Note that this will probably be a subfolder of the solution folder, with
  the same name as the project. For example:
  My Documents\VisualStudio\Projects\Shell\Shell\
5 In visual studio use :  Project...Add...Existing files.
  This will open a file dialogue. DO NOT BROWSE FOR THE FILES!
  If the files are not in the folder, move them into the right folder.
6 Go to Project .... Properties... VC++ Directories ... Include Directories 
  and add a new folder. 
  This will be the location of the DirectX SDK header files and is probably 
  “C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include;”. 
  If you run into problems here, you should check:
  a. There is a semicolon on the end. It may need it.
  b. Try putting this folder first in the list. If that doesn’t work, try last.
  c. Sometimes you need to do it for both the Debug and Release configuration. I suspect a bug in VS 2015.
7 Go to Project .... Properties... VC++ Directories ... Library Directories 
  and add a new folder. This will be the location of the DirectX SDK library files 
  and is probably “C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\lib\x86;”.
  Note the “\86” on the end. You can try “\64” if you want, but I have tested “\86” more carefully.

