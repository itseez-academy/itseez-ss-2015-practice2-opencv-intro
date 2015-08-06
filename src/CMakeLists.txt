set(target ${PRACTICE1_LIBRARY})

FILE(GLOB hdrs "*.h*" "${PRACTICE1_INCLUDE}/*.h*")
FILE(GLOB srcs "*.cpp")

ADD_LIBRARY(${target} STATIC ${srcs} ${hdrs})
TARGET_LINK_LIBRARIES(${target} ${LIBRARY_DEPS})
