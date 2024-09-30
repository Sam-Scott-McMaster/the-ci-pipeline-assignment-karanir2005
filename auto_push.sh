#!/bin/bash

if [ "$#" != 2 ]; then #checks if the number of agruments is not euqal to 2 
					   #and echos usage message and exits with code 1
    echo "Usage: $0 <commit_message> <tag_name>"
    exit 1
fi

MESSAGE=$1 #stores the first argument as commit message
TAG=$2 #second argument as tag name

#add, commits, tags, and pushes to main and tag.
git add .
git commit -m "$MESSAGE"
git tag "$TAG"
git push origin main
git push origin "$TAG_NAME"

#echos confirmation message
echo "Changes added, committed, tagged, and pushed successfully!"
