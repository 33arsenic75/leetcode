from concurrent import futures

class Solution:
    def get_hostname(self, url: str) -> str:
        return url.split('/')[2]

    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        seen = { startUrl }

        with futures.ThreadPoolExecutor(max_workers=5) as executor:
            future_set = { executor.submit(htmlParser.getUrls, startUrl) }

            while future_set:
                # get results as they complete
                for curr_future in futures.as_completed(future_set):
                    future_set.remove(curr_future)
                    retrieved_urls = curr_future.result()

                    for child_url in retrieved_urls:
                        # append seen and chain if necessary
                        if child_url not in seen and self.get_hostname(child_url) == self.get_hostname(startUrl):
                            seen.add(child_url)
                            future_set.add(executor.submit(htmlParser.getUrls, child_url))

        return list(seen)