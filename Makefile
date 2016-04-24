.PHONY: clean All

All:
	@echo "----------Building project:[ MallocWrapper - Debug ]----------"
	@cd "MallocWrapper" && $(MAKE) -f  "MallocWrapper.mk"
clean:
	@echo "----------Cleaning project:[ MallocWrapper - Debug ]----------"
	@cd "MallocWrapper" && $(MAKE) -f  "MallocWrapper.mk" clean
