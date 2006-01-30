/*=========================================================================

  Module:    KWWidgetsPythonExtraInit.cxx

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkPythonUtil.h"

#include "vtkKWTkUtilities.h"
#include "vtkKWObject.h"
#include "vtkKWApplication.h"

#include <stdlib.h>

// the init function for the python module
#if defined(_WIN32)
#if defined(__CYGWIN__)
extern "C" {void __declspec(dllexport) initlibKWWidgetsPython();}
#else /* defined(__CYGWIN__) */
extern "C" {void __declspec(dllexport) initKWWidgetsPython();}
#endif /* defined(__CYGWIN__) */
#else /* defined(_WIN32) */
extern "C" {void initlibKWWidgetsPython();}
#endif /* defined(_WIN32) */

// change the old "init" function into a pre-init function
#define initlibKWWidgetsPython preInitKWWidgetsPython
#define initKWWidgetsPython preInitKWWidgetsPython

// include the original init file
#include "KWWidgetsPythonInit.cxx"

// undefine
#undef initlibKWWidgetsPython
#undef initKWWidgetsPython

// define a bunch of extra stuff to go into the init file

//----------------------------------------------------------------------------
static PyObject *PyvtkKWObject_Script(PyObject *self, PyObject *args)
{
  char          *input;
  const char    *output;
  vtkKWObject   *op;
  PyObject *format_args = 0;
  PyObject *format_string = 0;
  int n;
  int i = 1;

  /* check whether this method is bound */
  if (PyVTKClass_Check(self))
    {
    i = 2;
    }

  /* Get the format string and arguments */
  n = PyTuple_Size(args);
  if (n >= i)
    {
    format_args = PyTuple_GetSlice(args,i,n);
    format_string = PyTuple_GetItem(args,i-1);
    /* Reslice args to not contain any format_args */
    args = PyTuple_GetSlice(args,0,i);
    }
  else
    {
    PyErr_Format(PyExc_TypeError,
                 "function takes at least %d argument (%d given)",
                 i, n);
    return NULL;
    }


  if (((op = (vtkKWObject *)PyArg_VTKParseTuple(self, args, (char*)"s",
                                                &input))))
    {
    PyObject *formatted_string;

    formatted_string = PyString_Format(format_string, format_args);
    if (formatted_string)
      {
      input = PyString_AsString(formatted_string);

      /* formatting again isn't very efficient, but is safe */
      if (PyVTKClass_Check(self))
        {
        output = op->vtkKWObject::Script("%s", input);
        }
      else
        {
        output = op->Script("%s", input);
        }

      Py_DECREF(formatted_string);
      Py_DECREF(format_args);
      Py_DECREF(args);

      if (output == NULL)
        {
        Py_INCREF(Py_None);
        return Py_None;
        }
      else
        {
        return PyString_FromString(output);
        }
      }
    }

  if (format_args)
    {
    Py_DECREF(format_args);
    Py_DECREF(args);
    }

  return NULL;
}

static PyObject *PyvtkKWApplication_Script(PyObject *self, PyObject *args)
{
  char          *input;
  const char    *output;
  vtkKWApplication *op;
  PyObject *format_args = 0;
  PyObject *format_string = 0;
  int n;
  int i = 1;

  /* check whether this method is bound */
  if (PyVTKClass_Check(self))
    {
    i = 2;
    }

  /* Get the format string and arguments */
  n = PyTuple_Size(args);
  if (n >= i)
    {
    format_args = PyTuple_GetSlice(args,i,n);
    format_string = PyTuple_GetItem(args,i-1);
    /* Reslice args to not contain any format_args */
    args = PyTuple_GetSlice(args,0,i);
    }
  else
    {
    PyErr_Format(PyExc_TypeError,
                 "function takes at least %d argument (%d given)",
                 i, n);
    return NULL;
    }

  if (((op = 
        (vtkKWApplication *)PyArg_VTKParseTuple(self, args, (char*)"s",
                                                &input))))
    {
    PyObject *formatted_string;

    formatted_string = PyString_Format(format_string, format_args);
    if (formatted_string)
      {
      input = PyString_AsString(formatted_string);

      /* formatting again isn't very efficient, but is safe */
      if (PyVTKClass_Check(self))
        {
        output = op->vtkKWObject::Script("%s", input);
        }
      else
        {
        output = op->Script("%s", input);
        }

      Py_DECREF(formatted_string);
      Py_DECREF(format_args);
      Py_DECREF(args);

      if (output == NULL)
        {
        Py_INCREF(Py_None);
        return Py_None;
        }
      else
        {
        return PyString_FromString(output);
        }
      }
    }

  if (format_args)
    {
    Py_DECREF(format_args);
    Py_DECREF(args);
    }

  return NULL;
}

static PyObject *PyvtkKWApplication_EvaluateBooleanExpression(PyObject *self,
                                                              PyObject *args)
{
  char          *input;
  long          output;
  vtkKWApplication *op;
  PyObject *format_args = 0;
  PyObject *format_string = 0;
  int n;
  int i = 1;

  /* check whether this method is bound */
  if (PyVTKClass_Check(self))
    {
    i = 2;
    }

  /* Get the format string and arguments */
  n = PyTuple_Size(args);
  if (n >= i)
    {
    format_args = PyTuple_GetSlice(args,i,n);
    format_string = PyTuple_GetItem(args,i-1);
    /* Reslice args to not contain any format_args */
    args = PyTuple_GetSlice(args,0,i);
    }
  else
    {
    PyErr_Format(PyExc_TypeError,
                 "function takes at least %d argument (%d given)",
                 i, n);
    return NULL;
    }

  if (((op = (vtkKWApplication *)PyArg_VTKParseTuple(self, args, (char*)"s",
                                                     &input))))
    {
    PyObject *formatted_string;

    formatted_string = PyString_Format(format_string, format_args);
    if (formatted_string)
      {
      input = PyString_AsString(formatted_string);

      /* formatting again isn't very efficient, but is safe */
      if (PyVTKClass_Check(self))
        {
        output = op->vtkKWApplication::EvaluateBooleanExpression("%s", input);
        }
      else
        {
        output = op->EvaluateBooleanExpression("%s", input);
        }

      Py_DECREF(formatted_string);
      Py_DECREF(format_args);
      Py_DECREF(args);

      return PyInt_FromLong(output);
      }
    }

  if (format_args)
    {
    Py_DECREF(format_args);
    Py_DECREF(args);
    }

  return NULL;
}


static PyObject *PyvtkKWApplication_InitializeTcl(PyObject *, PyObject *args)
{
  int argc;
  PyObject *pyargv;

  if ((PyArg_ParseTuple(args, (char*)"iO", &argc, &pyargv)))
    {
    static char emptystring[1] = "";
    int errcheck = 0;
    int l = 1;
    int i;
    PyObject *str;
    char *cp;
    char **argv;

    // make sure argv has at least one value
    if (argc > l)
      {
      l = argc;
      }

    argv = (char **)malloc(l*sizeof(char *));
    argv[0] = emptystring;

    for (i = 0; i < argc && errcheck == 0; i++)
      {
      errcheck = 1;
      str = PySequence_GetItem(pyargv, i);
      if (str)
        {
        cp = PyString_AsString(str);
        if (cp)
          {
          argv[i] = cp;
          errcheck = 0;
          }
        }
      }
    
    if (errcheck == 0)
      {
      vtkKWApplication::InitializeTcl(argc, argv);
      }

    free(argv);

    if (errcheck == 0)
      {
      Py_INCREF(Py_None);
      return Py_None;
      }
    }

  return NULL;
}

static PyObject *PyvtkKWApplication_Start(PyObject *self, PyObject *args)
{
  /* handle signature with no arguments */
  {
  vtkKWApplication *op;

  if ((op = (vtkKWApplication *)PyArg_VTKParseTuple(self, args, (char*)"")))
    {
    if (PyVTKClass_Check(self))
      {
      op->vtkKWApplication::Start();
      }
    else
      {
      op->Start();
      }
    Py_INCREF(Py_None);
    return Py_None;
    }
  }

  PyErr_Clear();
  /* handle signature with argc, argv arguments */
  {
  int argc;
  PyObject *pyargv;
  vtkKWApplication *op;

  if ((op = (vtkKWApplication *)PyArg_VTKParseTuple(self, args, (char*)"iO",
                                                    &argc, &pyargv)))
    {
    static char emptystring[1] = "";
    int errcheck = 0;
    int l = 1;
    int i;
    PyObject *str;
    char *cp;
    char **argv;

    // make sure argv has at least one value
    if (argc > l)
      {
      l = argc;
      }

    argv = (char **)malloc(l*sizeof(char *));
    argv[0] = emptystring;

    for (i = 0; i < argc && errcheck == 0; i++)
      {
      errcheck = 1;
      str = PySequence_GetItem(pyargv, i);
      if (str)
        {
        cp = PyString_AsString(str);
        if (cp)
          {
          argv[i] = cp;
          errcheck = 0;
          }
        }
      }
    
    if (errcheck == 0)
      {
      if (PyVTKClass_Check(self))
        {
        op->vtkKWApplication::Start(argc, argv);
        }
      else
        {
        op->Start(argc, argv);
        }
      }

    free(argv);

    if (errcheck == 0)
      {
      Py_INCREF(Py_None);
      return Py_None;
      }
    }
  }
  return NULL;
}


static PyMethodDef PyvtkKWApplicationPythonMethods[] = {
  {(char*)"Script",                (PyCFunction)PyvtkKWApplication_Script, 1,
   (char*)"V.Script(format, ...) -> string\nC++: const char *Script (const char *format, ...);\n\n Convenience methods to evaluate Tcl script/code and\n perform argument substitutions.\n"},
  {(char*)"EvaluateBooleanExpression",                (PyCFunction)PyvtkKWApplication_EvaluateBooleanExpression, 1,
   (char*)"V.EvaluateBooleanExpression(string) -> int\nC++: int EvaluateBooleanExpression (const char *text);\n\n Convenience methods to evaluate Tcl script/code and\n perform argument substitutions.\n"},
  {(char*)"Start",                (PyCFunction)PyvtkKWApplication_Start, 1,
   (char*)"V.Start()\nC++: virtual void Start ();\nV.Start(int argc, list argv)\nC++: virtual void Start (int argc, char *argv[])\n\n Start running the application, with or without arguments.\n"},
  {(char*)"InitializeTcl",                (PyCFunction)PyvtkKWApplication_InitializeTcl, 1,
   (char*)"V.InitializeTcl(int argc, list argv)\nC++: static void InitializeTcl (int argc, char *argv[]);\n\nInitialize Tcl/Tk\n Return NULL on error (eventually provides an ostream where detailed\n error messages will be stored).\n One method takes argc/argv and will create an internal Tcl interpreter\n on the fly, the other takes a Tcl interpreter and uses it afterward\n (this is mainly intended for initialization as a Tcl package)\n"},
  {NULL,                       NULL, 0, NULL}
};

static PyMethodDef PyvtkKWObjectPythonMethods[] = {
  {(char*)"PScript",                (PyCFunction)PyvtkKWObject_Script, 1,
   (char*)"V.Script(format, ...) -> string\nC++: const char *Script (const char *format, ...);\n\nreturn this Script EventString \n\n"},
  {NULL,                       NULL, 0, NULL}
};


void PyVTKClass_AddExtraMethods(PyVTKClass *self, PyMethodDef *methods)
{
  PyMethodDef *meth;

  // if dict isn't built yet, then build it
  if (self->vtk_dict == NULL)
    {
    self->vtk_dict = PyDict_New();

    for (meth = self->vtk_methods; meth && meth->ml_name; meth++)
      {
      PyDict_SetItemString(self->vtk_dict, meth->ml_name,
                           PyCFunction_New(meth, (PyObject *)self));
      }
    }

  // add new methods (this clobbers existing methods of the same name)
  for (meth = methods; meth && meth->ml_name; meth++)
    {
    PyDict_SetItemString(self->vtk_dict, meth->ml_name,
                         PyCFunction_New(meth, (PyObject *)self));
    }
}

/* define the init function for the module, handle different platforms */ 

#if defined(_WIN32) && !defined(__CYGWIN__)
void initKWWidgetsPython()
#else /* defined(_WIN32) && !defined(__CYGWIN__) */
void initlibKWWidgetsPython()
#endif /* defined(_WIN32) && !defined(__CYGWIN__) */
{
  // call init function from KWWidgetsPythonInit.cxx
  preInitKWWidgetsPython();

  // add extra items to module, on top of basic wrapping
  PyObject *dict = PyImport_GetModuleDict();

  if (dict == 0)
    {
    Py_FatalError((char*)"can't find module KWWidgetsPython!");
    return;
    }

  PyObject *module = 0;

#if defined(_WIN32) && !defined(__CYGWIN__)
  const char *modulename = "KWWidgetsPython";
#else
  const char *modulename = "libKWWidgetsPython";
#endif

  module = PyDict_GetItemString(dict, (char *)modulename);

  if (module == 0)
    {
    Py_FatalError((char*)"can't find module KWWidgetsPython!");
    return;
    }

  dict = PyModule_GetDict(module);

  if (dict == 0)
    {
    Py_FatalError((char*)"can't get dict for module KWWidgetsPython!");
    return;
    }

  PyObject *pyclass = 0;

  // add vtkKWObject methods

  pyclass = PyDict_GetItemString(dict, "vtkKWObject");

  if (pyclass == 0 || PyVTKClass_Check(pyclass) == 0)
    {
    Py_FatalError((char*)"can't find vtkKWObject class!");
    return;
    }
  
  PyVTKClass_AddExtraMethods((PyVTKClass *)pyclass,
                             PyvtkKWObjectPythonMethods);

  // add vtkKWApplication methods

  pyclass = PyDict_GetItemString(dict, "vtkKWApplication");

  if (pyclass == 0 || PyVTKClass_Check(pyclass) == 0)
    {
    Py_FatalError((char*)"can't find vtkKWApplication class!");
    return;
    }
  
  PyVTKClass_AddExtraMethods((PyVTKClass *)pyclass,
                             PyvtkKWApplicationPythonMethods);
}
 
