# `entities` = concrete game objects built on top of `core` (Starship now,
# Planet/Debris later). Depends on core/, never the other way around.
add_library(entities
    Starship.cpp
)

target_include_directories(entities PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# PUBLIC: Starship.hpp publicly inherits PhysicsEntity ("class Starship :
# public PhysicsEntity"), so anyone who includes Starship.hpp needs
# PhysicsEntity.hpp visible too. Linking `core` PUBLIC here is what lets
# that requirement (and raylib, transitively via core) reach main.cpp
# without main.cpp having to link core or raylib itself.
target_link_libraries(entities PUBLIC core)
