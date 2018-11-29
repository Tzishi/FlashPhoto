EXECUTE=../build/MIA/bin/MIA
GOLDENDIR=golden-images
TESTDIR=test-images
PHOTOPATH=../resources/test-images
SEQPATH=$(PHOTOPATH)/brainstack
NORMALPHOTOFILES:= brainColor.jpg graphWithoutAlpha.png
# SEQPHOTOFILES:=$(wildcard $(PHOTOPATH)/brainstack/*.*)
# SEQPHOTOFILES:=$(notdir $(SEQPHOTOFILES))
# SEQ_GOLDENFILES:=$(addprefix $(GOLDENDIR)/, $(SEQPHOTOFILES))

all: setup test

setup: | ../build
	$(MAKE) -C../

golden: $(NOR_GOLDENFILES) setup  |$(GOLDENDIR)
	@echo making golden-images...
	sh golden-images-generator.sh
	@echo golden-images done.

test: |$(TESTDIR)
	@echo
	@echo
	@echo
	@echo Testing Functionalities
	@sh functionality-test.sh
	@echo Testing Invalid Inputs
	@sh bad-inputs-test.sh
	@echo
	@echo
	@echo
	
$(TESTDIR):
	mkdir $@
	mkdir $@/brainstack

$(GOLDENDIR):
	mkdir $@
	mkdir $@/brainstack

../build:
	mkdir $@

clean:
	rm -rf $(GOLDENDIR) $(TESTDIR)
