BEGIN {
D["PACKAGE_NAME"]=" \"mpich-testsuite\""
D["PACKAGE_TARNAME"]=" \"mpich-testsuite\""
D["PACKAGE_VERSION"]=" \"3.3a2\""
D["PACKAGE_STRING"]=" \"mpich-testsuite 3.3a2\""
D["PACKAGE_BUGREPORT"]=" \"discuss@mpich.org\""
D["PACKAGE_URL"]=" \"http://www.mpich.org/\""
D["PACKAGE"]=" \"mpich-testsuite\""
D["VERSION"]=" \"3.3a2\""
D["HAVE_MPI_SPAWN"]=" 1"
D["HAVE_MPI_WIN_CREATE"]=" 1"
D["HAVE_LONG_DOUBLE"]=" 1"
D["HAVE_LONG_LONG"]=" 1"
D["restrict"]=" __restrict"
D["STDC_HEADERS"]=" 1"
D["HAVE_SYS_TYPES_H"]=" 1"
D["HAVE_SYS_STAT_H"]=" 1"
D["HAVE_STDLIB_H"]=" 1"
D["HAVE_STRING_H"]=" 1"
D["HAVE_MEMORY_H"]=" 1"
D["HAVE_STRINGS_H"]=" 1"
D["HAVE_INTTYPES_H"]=" 1"
D["HAVE_STDINT_H"]=" 1"
D["HAVE_UNISTD_H"]=" 1"
D["HAVE_STDARG_H"]=" 1"
D["HAVE_SYS_TIME_H"]=" 1"
D["HAVE_SYS_RESOURCE_H"]=" 1"
D["HAVE__BOOL"]=" 1"
D["HAVE_FLOAT__COMPLEX"]=" 1"
D["HAVE_DOUBLE__COMPLEX"]=" 1"
D["HAVE_LONG_DOUBLE__COMPLEX"]=" 1"
D["SIZEOF_VOID_P"]=" 8"
D["USE_LONG_DOUBLE_COMPLEX"]=" 1"
D["HAVE_H_ADDR_LIST"]=" 1"
D["HAVE_GETRUSAGE"]=" 1"
D["HAVE_MPI_IO"]=" 1"
D["SIZEOF_VOID_P"]=" 8"
D["SIZEOF_INT"]=" 4"
D["SIZEOF_LONG"]=" 8"
D["SIZEOF_LONG_LONG"]=" 8"
D["SIZEOF_SHORT"]=" 2"
D["POINTERINT_t"]=" long"
  for (key in D) D_is_set[key] = 1
  FS = ""
}
/^[\t ]*#[\t ]*(define|undef)[\t ]+[_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ][_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789]*([\t (]|$)/ {
  line = $ 0
  split(line, arg, " ")
  if (arg[1] == "#") {
    defundef = arg[2]
    mac1 = arg[3]
  } else {
    defundef = substr(arg[1], 2)
    mac1 = arg[2]
  }
  split(mac1, mac2, "(") #)
  macro = mac2[1]
  prefix = substr(line, 1, index(line, defundef) - 1)
  if (D_is_set[macro]) {
    # Preserve the white space surrounding the "#".
    print prefix "define", macro P[macro] D[macro]
    next
  } else {
    # Replace #undef with comments.  This is necessary, for example,
    # in the case of _POSIX_SOURCE, which is predefined and required
    # on some systems where configure will not decide to define it.
    if (defundef == "undef") {
      print "/*", prefix defundef, macro, "*/"
      next
    }
  }
}
{ print }
