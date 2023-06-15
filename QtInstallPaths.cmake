if(TARGET Qt6::qmake)
  get_target_property(QT_QMAKE_EXECUTABLE Qt6::qmake IMPORTED_LOCATION)
elseif(TARGET Qt5::qmake)
  get_target_property(QT_QMAKE_EXECUTABLE Qt5::qmake IMPORTED_LOCATION)
elseif(TARGET Qt4::qmake)
  get_target_property(QT_QMAKE_EXECUTABLE Qt4::qmake IMPORTED_LOCATION)
else()
  message(FATAL_ERROR "No supported Qt version found. Make sure you find Qt before calling this")
endif()

execute_process(
  COMMAND ${QT_QMAKE_EXECUTABLE} -query
  RESULT_VARIABLE return_code
  OUTPUT_VARIABLE ALL_VARS
)
if(NOT return_code EQUAL 0)
  message(WARNING "Failed call: ${QMAKE_EXECUTABLE} -query")
  message(FATAL_ERROR "QMake call failed: ${return_code}")
endif()

string(REPLACE "\n" ";" VARS_LIST ${ALL_VARS})
foreach(QVAL ${VARS_LIST})
  if(QVAL MATCHES "QT_INSTALL_")
    string(REPLACE ":" ";" QVAL_LIST ${QVAL})
    list(LENGTH QVAL_LIST listlen)
    list(GET QVAL_LIST 0 var)
    if(WIN32 AND ${listlen} GREATER 2)
      list(GET QVAL_LIST 2 path)
      list(GET QVAL_LIST 1 drive)
      set(path "${drive}:${path}")
    else()
      list(GET QVAL_LIST 1 path)
    endif()
    if(NOT ${var}) #if set already on the command line for example
      set(${var} ${path} CACHE PATH "Qt install path for ${var}")
    endif()
  endif()
endforeach()

