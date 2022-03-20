# GIT使用笔记

## 1.创建版本库

$mkdir textname(创建)

$cd textname （加载）

$pwd （显示目录所在位置）

$git init （把这个目录变成git可管理的仓库）

## 2.添加文件到目录

*注意添加文件前要把文件方法到textname的目录中（子目录也可）

$git add /////(把工作区的文件添加到暂存区，add 一次可添加多个文件，文件名字之间用","隔开)

$git commit -m " ......"(把暂存区中的文件提交到git仓库，"........"中可添加本次提交的描述，eg：改动了什么，添加了什么)

$git status  查看当前仓库的状态

## 3.版本回退

$git log命令显示从最近到最远的提交日志,即提交历史，同时可看到commit id。

HEAD表示当前版本，HEAD^表示上一版本，上n个版本：HEAD~n。

$git reset --head HEAD~n，回退到上n个版本

或 git reset --head commit id	。

$git reflog可查看命令历史。

## 4.远程仓库

$git add remote origin git@github.com:username/textname.git

将本地仓库关联到远程仓库

$git push -u origin master

第一次推送master分支的所有内容，之后本地仓库内容有更新可用git push origin master香远程仓库推送最新的版本。

