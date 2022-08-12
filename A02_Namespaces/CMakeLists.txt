cmake_minimum_required(VERSION 3.22)
include("../Build/compileAll.cmake")
project(CMAKE)


all: subsystems

subsystems:
	@cd NamespaceExamples && $(MAKE)
	@cd NamespacesInLibraries && $(MAKE)

clean:
	@cd NamespaceExamples && $(MAKE) clean
	@cd NamespacesInLibraries && $(MAKE) clean


