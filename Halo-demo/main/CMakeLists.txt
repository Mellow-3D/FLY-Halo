file(GLOB SOURCES_MAIN "./*.c")
file(GLOB SOURCES_TOOLS_WIFI "tools/wifi/*.c")
file(GLOB SOURCES_IMGS "static/images/*.c")
file(GLOB SOURCES_FONTS "static/fonts/*.c")

file(GLOB SOURCES_MUSIC "../components/lvgl/demos/music/*.c" "../components/lvgl/demos/music/assets/*.c")


idf_component_register(SRCS ${SOURCES_MAIN}
                        ${SOURCES_TOOLS_WIFI}
                        ${SOURCES_IMGS}
                        ${SOURCES_FONTS}
                        ${SOURCES_MUSIC}
                       INCLUDE_DIRS ".")
