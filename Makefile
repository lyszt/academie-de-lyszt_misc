WEBAPP := webapp

.PHONY: help install run build start clean

help:
	@echo "make install  - install webapp dependencies"
	@echo "make run       - run server + client in watch mode (http://localhost:5173)"
	@echo "make build     - build client for production"
	@echo "make start     - run the API server without watch mode"
	@echo "make clean      - remove build output and installed dependencies"

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
