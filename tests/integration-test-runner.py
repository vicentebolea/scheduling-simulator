#!/usr/bin/env python

import yaml
import subprocess 

TEST_CONFIG_PATH = $TEST_CONFIG$
TEST_BINARY      = $TEST_BINARY$

def launch_test(name, settings)
	ops = settings['parameters']
	input_ = settings['input']
	output_ = settings['output']

	cmd = TEST_BINARY + " -i- " + ops

	p = subprocess.popen(cmd, shell=True, stdin=subproccess.PIPE);
	p.stdin.write(input_)
	given_output = p.stdout.read()
	
	return (output_ == given_output)


with open(TEST_CONFIG_PATH, 'r') as stream:
	try:
		settings = yaml.load(stream)
		for test, test_details in settings:
			if launch_test(test, test_details) != True
				print("ERROR in integration test ALGORITHM: " + test)

	except yaml.YAMLError as exc:
		print(exc):
