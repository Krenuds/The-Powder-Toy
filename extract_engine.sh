#!/bin/bash
# Script to extract bare bones engine from The Powder Toy

# Create new project structure
mkdir -p minimal-engine/src/{common,graphics,gui/interface,input,engine}

# Copy core utilities
cp -r src/common/String.* minimal-engine/src/common/
cp -r src/common/Vec2.h minimal-engine/src/common/
cp -r src/common/tpt-rand.* minimal-engine/src/common/
cp -r src/common/platform/ minimal-engine/src/common/
cp -r src/common/ExplicitSingleton.h minimal-engine/src/common/

# Copy graphics engine (excluding simulation-specific parts)
cp src/graphics/Graphics.* minimal-engine/src/graphics/
cp src/graphics/Renderer.h minimal-engine/src/graphics/
cp src/graphics/VideoBuffer.h minimal-engine/src/graphics/
cp src/graphics/RasterGraphics.* minimal-engine/src/graphics/
cp src/graphics/Pixel.h minimal-engine/src/graphics/
cp src/graphics/RasterDrawMethods.h minimal-engine/src/graphics/

# Copy UI framework core
cp src/gui/interface/Engine.* minimal-engine/src/gui/interface/
cp src/gui/interface/Component.* minimal-engine/src/gui/interface/
cp src/gui/interface/Window.* minimal-engine/src/gui/interface/
cp src/gui/interface/Panel.* minimal-engine/src/gui/interface/
cp src/gui/interface/Button.* minimal-engine/src/gui/interface/
cp src/gui/interface/Label.* minimal-engine/src/gui/interface/

# Copy input handling
cp src/PowderToySDL.h minimal-engine/src/input/SDLWrapper.h
cp src/SDLCompat.* minimal-engine/src/input/

# Copy essential headers
cp src/Config.template.h minimal-engine/src/Config.h

echo "Bare bones engine extracted!"
echo "Remove simulation-specific code from Renderer.cpp"
echo "Create your own GameEngine class in src/engine/"
