cmake_minimum_required(VERSION 2.8)

include(TycheCashWallet.cmake)

project(${CN_PROJECT_NAME})
set(TycheCash_LIB TycheCash)
set(CMAKE_PREFIX_PATH C:/Qt/5.10.1/msvc2017_64)


include_directories(${CMAKE_BINARY_DIR}
    src
    TycheCash/external
    TycheCash/include
    TycheCash/src)

find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(Boost_USE_STATIC_LIBS ON)
if(WIN32)
  set(Boost_USE_STATIC_RUNTIME OFF)
else(WIN32)
  set(Boost_USE_STATIC_RUNTIME ON)
endif(WIN32)

find_package(Boost 1.55 REQUIRED COMPONENTS date_time filesystem program_options regex serialization system thread chrono)
if ((${Boost_MAJOR_VERSION} EQUAL 1) AND (${Boost_MINOR_VERSION} EQUAL 54))
	message(SEND_ERROR "Boost version 1.54 is unsupported, more details are available here http://goo.gl/RrCFmA")
endif ()

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

set(VERSION "")
configure_file("TycheCash/src/version.h.in" "version.h")
configure_file("src/TycheCashWalletConfig.h.in" "TycheCashWalletConfig.h")

add_definitions(-DGIT_REVISION=\"${GIT_REVISION}\")

set(CMAKE_AUTOMOC ON)

set(TycheCash_SOURCES
  TycheCash/external/miniupnpc/connecthostport.c
  TycheCash/external/miniupnpc/igd_desc_parse.c
  TycheCash/external/miniupnpc/minisoap.c
  TycheCash/external/miniupnpc/miniupnpc.c
  TycheCash/external/miniupnpc/miniwget.c
  TycheCash/external/miniupnpc/minixml.c
  TycheCash/external/miniupnpc/portlistingparse.c
  TycheCash/external/miniupnpc/receivedata.c
  TycheCash/external/miniupnpc/upnpcommands.c
  TycheCash/external/miniupnpc/upnpreplyparse.c
  TycheCash/src/Common/Base58.cpp
  TycheCash/src/Common/CommandLine.cpp
  TycheCash/src/Common/Util.cpp
  TycheCash/src/Common/StringTools.cpp
  TycheCash/src/Common/JsonValue.cpp
  TycheCash/src/Common/ConsoleTools.cpp
  TycheCash/src/Common/MemoryInputStream.cpp
  TycheCash/src/Common/PathTools.cpp
  TycheCash/src/Common/StdInputStream.cpp
  TycheCash/src/Common/StdOutputStream.cpp
  TycheCash/src/Common/StreamTools.cpp
  TycheCash/src/Common/StringOutputStream.cpp
  TycheCash/src/Common/StringView.cpp
  TycheCash/src/Common/VectorOutputStream.cpp
  TycheCash/src/crypto/blake256.c
  TycheCash/src/crypto/chacha8.c
  TycheCash/src/crypto/crypto-ops-data.c
  TycheCash/src/crypto/crypto-ops.c
  TycheCash/src/crypto/crypto.cpp
  TycheCash/src/crypto/groestl.c
  TycheCash/src/crypto/hash-extra-blake.c
  TycheCash/src/crypto/hash-extra-groestl.c
  TycheCash/src/crypto/hash-extra-jh.c
  TycheCash/src/crypto/hash-extra-skein.c
  TycheCash/src/crypto/hash.c
  TycheCash/src/crypto/jh.c
  TycheCash/src/crypto/keccak.c
  TycheCash/src/crypto/oaes_lib.c
  TycheCash/src/crypto/random.c
  TycheCash/src/crypto/skein.c
  TycheCash/src/crypto/slow-hash.c
  TycheCash/src/crypto/slow-hash.cpp
  TycheCash/src/crypto/tree-hash.c
  TycheCash/src/TycheCashCore/BlockchainIndices.cpp
  TycheCash/src/TycheCashCore/BlockchainMessages.cpp
  TycheCash/src/TycheCashCore/BlockIndex.cpp
  TycheCash/src/TycheCashCore/CoreConfig.cpp
  TycheCash/src/TycheCashCore/TycheCashBasic.cpp
  TycheCash/src/TycheCashCore/TycheCashTools.cpp
  TycheCash/src/TycheCashCore/Currency.cpp
  TycheCash/src/TycheCashCore/MinerConfig.cpp
  TycheCash/src/TycheCashCore/Transaction.cpp
  TycheCash/src/TycheCashCore/Account.cpp
  TycheCash/src/TycheCashCore/Blockchain.cpp
  TycheCash/src/TycheCashCore/Checkpoints.cpp
  TycheCash/src/TycheCashCore/TycheCashBasicImpl.cpp
  TycheCash/src/TycheCashCore/Core.cpp
  TycheCash/src/TycheCashCore/TycheCashFormatUtils.cpp
  TycheCash/src/TycheCashCore/TycheCashSerialization.cpp
  TycheCash/src/TycheCashCore/Difficulty.cpp
  TycheCash/src/TycheCashCore/IBlock.cpp
  TycheCash/src/TycheCashCore/Miner.cpp
  TycheCash/src/TycheCashCore/TransactionExtra.cpp
  TycheCash/src/TycheCashCore/TransactionPool.cpp
  TycheCash/src/TycheCashCore/TransactionPrefixImpl.cpp
  TycheCash/src/TycheCashCore/TransactionUtils.cpp
  TycheCash/src/InProcessNode/InProcessNode.cpp
  TycheCash/src/InProcessNode/InProcessNodeErrors.cpp
  TycheCash/src/NodeRpcProxy/NodeErrors.cpp
  TycheCash/src/NodeRpcProxy/NodeRpcProxy.cpp
  TycheCash/src/P2p/NetNodeConfig.cpp
  TycheCash/src/Serialization/BinaryInputStreamSerializer.cpp
  TycheCash/src/Serialization/BinaryOutputStreamSerializer.cpp
  TycheCash/src/Serialization/JsonInputValueSerializer.cpp
  TycheCash/src/Serialization/JsonOutputStreamSerializer.cpp
  TycheCash/src/Serialization/KVBinaryInputStreamSerializer.cpp
  TycheCash/src/Serialization/KVBinaryOutputStreamSerializer.cpp
  TycheCash/src/Serialization/SerializationOverloads.cpp
  TycheCash/src/Transfers/BlockchainSynchronizer.cpp
  TycheCash/src/Transfers/SynchronizationState.cpp
  TycheCash/src/Transfers/TransfersConsumer.cpp
  TycheCash/src/Transfers/TransfersContainer.cpp
  TycheCash/src/Transfers/TransfersSubscription.cpp
  TycheCash/src/Transfers/TransfersSynchronizer.cpp
  TycheCash/src/Wallet/LegacyKeysImporter.cpp
  TycheCash/src/Wallet/WalletAsyncContextCounter.cpp
  TycheCash/src/Wallet/WalletErrors.cpp
  TycheCash/src/WalletLegacy/KeysStorage.cpp
  TycheCash/src/WalletLegacy/WalletLegacy.cpp
  TycheCash/src/WalletLegacy/WalletHelper.cpp
  TycheCash/src/WalletLegacy/WalletLegacySerializer.cpp
  TycheCash/src/WalletLegacy/WalletLegacySerialization.cpp
  TycheCash/src/WalletLegacy/WalletTransactionSender.cpp
  TycheCash/src/WalletLegacy/WalletUnconfirmedTransactions.cpp
  TycheCash/src/WalletLegacy/WalletUserTransactionsCache.cpp
  TycheCash/src/System/ContextGroup.cpp
  TycheCash/src/System/Event.cpp
  TycheCash/src/System/EventLock.cpp
  TycheCash/src/System/InterruptedException.cpp
  TycheCash/src/System/Ipv4Address.cpp
  TycheCash/src/System/TcpStream.cpp
  TycheCash/src/HTTP/HttpRequest.cpp
  TycheCash/src/HTTP/HttpParser.cpp
  TycheCash/src/HTTP/HttpParserErrorCodes.cpp
  TycheCash/src/HTTP/HttpResponse.cpp
  TycheCash/src/Rpc/HttpClient.cpp
  TycheCash/src/Rpc/JsonRpc.cpp
  TycheCash/src/P2p/NetNode.cpp
  TycheCash/src/P2p/LevinProtocol.cpp
  TycheCash/src/P2p/NetNodeConfig.cpp
  TycheCash/src/P2p/PeerListManager.cpp
  TycheCash/src/TycheCashProtocol/TycheCashProtocolHandler.cpp
  TycheCash/src/Logging/ILogger.cpp
  TycheCash/src/Logging/LoggerGroup.cpp
  TycheCash/src/Logging/CommonLogger.cpp
  TycheCash/src/Logging/LoggerManager.cpp
  TycheCash/src/Logging/FileLogger.cpp
  TycheCash/src/Logging/StreamLogger.cpp
  TycheCash/src/Logging/ConsoleLogger.cpp
  TycheCash/src/Logging/LoggerMessage.cpp
  TycheCash/src/Logging/LoggerRef.cpp
  TycheCash/src/BlockchainExplorer/BlockchainExplorer.cpp
  TycheCash/src/BlockchainExplorer/BlockchainExplorerDataBuilder.cpp
  TycheCash/src/BlockchainExplorer/BlockchainExplorerErrors.cpp
)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS src/*.h)
file(GLOB_RECURSE FORMS src/gui/ui/*.ui)

set(QRC src/resources.qrc)

qt5_wrap_ui(UIS ${FORMS})
qt5_add_resources(RCC ${QRC})


if (WIN32)
  if (NOT MSVC)
	message(FATAL_ERROR "Only MSVC is supported on this platform")
  endif ()
  add_definitions(/D_CRT_SECURE_NO_WARNINGS /D_WIN32_WINNT=0x0600 /DSTATICLIB)
  include_directories(TycheCash/src/platform/msc)

  set(PLATFORM_DIR Windows)
  set(BUILD_PLATFORM WIN32)
  set(BUILD_RESOURCES src/TycheCashwallet.rc)
  set(QTMAIN Qt5::WinMain)

elseif (UNIX)
  set(TycheCash_SOURCES ${TycheCash_SOURCES} TycheCash/external/miniupnpc/minissdpc.c)
  if (APPLE)
    enable_language(ASM)
    file(GLOB_RECURSE OBJC_SOURCES src/*.mm)
    set(SOURCES ${SOURCES} ${OBJC_SOURCES})
    set(PLATFORM_DIR OSX)
    set(MACOSX_BUNDLE_INFO_STRING "TycheCash GUI wallet")
    set(MACOSX_BUNDLE_LONG_VERSION_STRING "${VERSION_VERSION}.${VERSION_MINOR}.${VERSION_PATCH}")
    set(MACOSX_BUNDLE_BUNDLE_NAME TycheCashWallet)
    set(MACOSX_BUNDLE_SHORT_VERSION_STRING "${VERSION_VERSION}.${VERSION_MINOR}.${VERSION_PATCH}")
    set(MACOSX_BUNDLE_BUNDLE_VERSION "$${VERSION_VERSION}.${VERSION_MINOR}.${VERSION_PATCH}")

    find_package(Qt5PrintSupport REQUIRED)

    include_directories(/usr/include/malloc)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -maes -std=c++11 -stdlib=libc++")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -maes -D_DARWIN_C_SOURCE")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework OpenGL -framework CoreFoundation -framework Carbon -framework IOKit -L/usr/lib")

    set(MACOSX_BUNDLE_ICON_FILE TycheCash.icns)
    set(APPLICATION_ICON src/images/TycheCash.icns)
    set_source_files_properties(${APPLICATION_ICON} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

    set(BUILD_PLATFORM MACOSX_BUNDLE)
    set(BUILD_RESOURCES ${APPLICATION_ICON})
	
    GET_TARGET_PROPERTY(QT_LIB_DIR "${Qt5Widgets_LIBRARIES}" LOCATION)
    GET_FILENAME_COMPONENT(QT_LIB_DIR "${QT_LIB_DIR}" PATH)
  else(APPLE)
    set(PLATFORM_DIR Linux)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -maes -std=c++11")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -maes -std=c11")
  endif (APPLE)
endif ()

include_directories(TycheCash/src/Platform/${PLATFORM_DIR})
file(GLOB PLATFORM_SOURCES TycheCash/src/Platform/${PLATFORM_DIR}/System/*)
set(TycheCash_SOURCES ${TycheCash_SOURCES} ${PLATFORM_SOURCES})

add_library(${TycheCash_LIB} STATIC ${TycheCash_SOURCES})
set_target_properties(${TycheCash_LIB} PROPERTIES COMPILE_DEFINITIONS _GNU_SOURCE)
target_link_libraries(${TycheCash_LIB} ${Boost_LIBRARIES})

add_executable(${PROJECT_NAME} ${BUILD_PLATFORM} ${BUILD_RESOURCES} ${SOURCES} ${HEADERS} ${UIS} ${RCC})
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS _GNU_SOURCE)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${QTMAIN} ${TycheCash_LIB})

if (APPLE)
  qt5_use_modules(${PROJECT_NAME} PrintSupport)
elseif (UNIX)
  target_link_libraries(${PROJECT_NAME} -lpthread)
elseif (WIN32)
  target_link_libraries(${PROJECT_NAME} Imm32 Iphlpapi Winmm)
endif (APPLE)

qt5_use_modules(${PROJECT_NAME} Widgets Gui)
