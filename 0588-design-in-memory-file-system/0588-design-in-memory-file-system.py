class Node:
    def __init__(self):
        self.children = {}      # name -> Node (used for directories)
        self.is_file = False
        self.content = ""


class FileSystem:

    def __init__(self):
        self.root = Node()

    def _walk(self, path: str, create: bool = False) -> Node:
        node = self.root
        for name in path.split("/"):
            if not name:                      # skips empty parts ("/" or leading slash)
                continue
            if name not in node.children:
                if not create:
                    return None
                node.children[name] = Node()
            node = node.children[name]
        return node

    def ls(self, path: str) -> list[str]:
        node = self._walk(path)
        if node.is_file:
            return [path.split("/")[-1]]      # a file returns just its own name
        return sorted(node.children.keys())

    def mkdir(self, path: str) -> None:
        self._walk(path, create=True)         # creates all missing directories on the way

    def addContentToFile(self, filePath: str, content: str) -> None:
        node = self._walk(filePath, create=True)
        node.is_file = True
        node.content += content

    def readContentFromFile(self, filePath: str) -> str:
        return self._walk(filePath).content


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)