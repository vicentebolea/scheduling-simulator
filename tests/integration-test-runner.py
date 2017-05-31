#!/usr/bin/env python

import yaml
import subprocess 
import os
import sys

# use AM_TESTS_ENVIRONMENT
TEST_CONFIG_PATH = os.environ['TEST_CONFIG']
TEST_BINARY      = os.environ['TEST_BINARY']

def die(str_):
	print(str_)
	sys.exit(-1)

def launch_test(settings):
	name = settings['algorithm']
	ops = settings['parameters']
	input_ = settings['input']
	output_ = settings['output']

	cmd = TEST_BINARY + " -i - " + ops

	p = subprocess.Popen(cmd, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE);
	p.stdin.write(input_)
	p.stdin.close()
	given_output = p.stdout.read()

	test = (output_ == given_output)
	if not test:
		print("Code output: ")
		print(given_output)
		print("Reference output: ")
		print(output_)
	
	return test

def main():
	with open(TEST_CONFIG_PATH, 'r') as stream:
		try:
			settings = yaml.load(stream)
			for test in settings:
				name = test['algorithm']
				if launch_test(test) != True:
					die("ERROR in integration test ALGORITHM: " + name)

		except yaml.YAMLError as exc:
			print(exc)


if __name__ == "__main__":
	main()
