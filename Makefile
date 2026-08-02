WEBAPP := webapp

CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall
CP_DIR := Experiments/Competitive Programming

.PHONY: help install run build start clean compile compile-clean

help:
	@echo "make install  - install webapp dependencies"
	@echo "make run       - run server + client in watch mode (http://localhost:5173)"
	@echo "make build     - build client for production"
	@echo "make start     - run the API server without watch mode"
	@echo "make clean      - remove build output and installed dependencies"
	@echo "make compile    - compile all C++ under Competitive Programming"
	@echo "make compile-clean - remove compiled C++ binaries"

compile:
	@find "$(CP_DIR)" -name '*.cpp' -print0 | while IFS= read -r -d '' src; do \
		echo "CXX $$src"; \
		$(CXX) $(CXXFLAGS) "$$src" -o "$${src%.cpp}.out" || echo "FAILED $$src"; \
	done

compile-clean:
	@find "$(CP_DIR)" -name '*.out' -delete

install:
	npm --prefix $(WEBAPP) install

run:
	npm --prefix $(WEBAPP) run dev

build:
	npm --prefix $(WEBAPP) run build

start:
	npm --prefix $(WEBAPP)/server run start

clean:
	rm -rf $(WEBAPP)/node_modules $(WEBAPP)/server/node_modules $(WEBAPP)/client/node_modules
	rm -rf $(WEBAPP)/client/dist $(WEBAPP)/server/dist
