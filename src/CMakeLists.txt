target_include_directories(${target} PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_sources(${target} PRIVATE
    main.cpp
    
    1541d64.cpp
    1541fs.cpp
    1541gcr.cpp
    1541t64.cpp
    Cartridge.cpp
    CPU_common.cpp
    Display.cpp
    IEC.cpp
    Prefs.cpp
    REU.cpp
    SAM.cpp
    SID.cpp
    Tape.cpp
)

target_sources(${target} PRIVATE
    C64_SC.cpp
    CIA_SC.cpp
    CPU1541_SC.cpp
    CPUC64_SC.cpp
    VIA_SC.cpp
    VIC_SC.cpp
)

if(FALSE)
target_sources(${target} PRIVATE
    C64.cpp
    CIA.cpp
    CPU1541.cpp
    CPUC64.cpp
    VIA.cpp
    VIC.cpp
)
endif()