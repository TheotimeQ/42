#!/bin/bash
ifconfig | grep ether | sed 's/ether//' | sed 's/ //g' | grep -v 'media' | tr -d '	'  
