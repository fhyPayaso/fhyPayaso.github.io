# 上传前更新搜索
export HEXO_ALGOLIA_INDEXING_KEY=8c672bfc6f286f45d670b2a090f428a5
hexo algolia

# hexo 部署
hexo clean
hexo g
# 压缩
# gulp
# 部署
hexo d
echo "部署成功辣ヾ(o◕∀◕)ﾉヾ"

# # github备份
# commit_msg=$1
# git add .
# echo "add 完毕"
# git commit -m${commit_msg}
# echo "commit 完毕"
# git push origin hexo

