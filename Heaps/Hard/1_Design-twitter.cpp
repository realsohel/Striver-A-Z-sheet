#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:
    // followerId -> set of followeeIds
    unordered_map<int, unordered_set<int>> followersMap;

    // userId -> max heap of {timestamp, tweetId}
    unordered_map<int, priority_queue<pair<int,int>>> userTweets;

    int globalTimestamp;

    Twitter() {
        globalTimestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push({globalTimestamp, tweetId});
        globalTimestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int,int>> mergedTweets;

        vector<pair<int,int>> userTweetBackup;
        while (!userTweets[userId].empty()) {
            auto tweet = userTweets[userId].top();
            mergedTweets.push(tweet);
            userTweetBackup.push_back(tweet);
            userTweets[userId].pop();
        }
        for (auto &tweet : userTweetBackup) {
            userTweets[userId].push(tweet);
        }

        for (int followeeId : followersMap[userId]) {
            vector<pair<int,int>> followeeTweetBackup;

            while (!userTweets[followeeId].empty()) {
                auto tweet = userTweets[followeeId].top();
                mergedTweets.push(tweet);
                followeeTweetBackup.push_back(tweet);
                userTweets[followeeId].pop();
            }

            for (auto &tweet : followeeTweetBackup) {
                userTweets[followeeId].push(tweet);
            }
        }

        vector<int> newsFeed;
        int feedCount = 0;

        while (!mergedTweets.empty() && feedCount < 10) {
            newsFeed.push_back(mergedTweets.top().second);
            mergedTweets.pop();
            feedCount++;
        }

        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        followersMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followersMap[followerId].erase(followeeId);
    }
};



// ========================================= EXPLANATION =========================================
//
// Answer: This problem implements a simplified version of **Twitter**, supporting the following
// operations:
// 1. Post a tweet
// 2. Follow a user
// 3. Unfollow a user
// 4. Get the 10 most recent tweets in a user's news feed
//
// The news feed consists of:
// → Tweets posted by the user themselves
// → Tweets posted by users they follow
// → Ordered by **most recent first**
//
// ----------------------------------------------------------------------------------------------
// CORE IDEA
// ----------------------------------------------------------------------------------------------
// - Each user has their own tweets stored in a **max-heap** (priority queue)
// - Tweets are ordered using a **global timestamp**
// - Follow relationships are stored using a hash map of sets
// - While generating the news feed, we **temporarily merge tweets** from multiple users
//   without permanently modifying stored data
//
// This ensures:
// ✔ Correct ordering by recency
// ✔ `unfollow()` works naturally
// ✔ No stale tweets remain in the feed
//
// ----------------------------------------------------------------------------------------------
// DATA MEMBERS
// ----------------------------------------------------------------------------------------------
//
// unordered_map<int, unordered_set<int>> followersMap
// - Maps: followerId → set of followeeIds
// - Example: followersMap[1] = {2, 3}
//
// unordered_map<int, priority_queue<pair<int,int>>> userTweets
// - Maps: userId → max heap of {timestamp, tweetId}
// - The tweet with the highest timestamp is always on top
//
// int globalTimestamp
// - Acts as a global clock
// - Increases with every posted tweet
// - Ensures unique and correct ordering of tweets
//
// ----------------------------------------------------------------------------------------------
// CONSTRUCTOR
// ----------------------------------------------------------------------------------------------
//
// Twitter()
// - Initializes the global timestamp to 0
// - The first tweet gets timestamp 0, next gets 1, and so on
//
// ----------------------------------------------------------------------------------------------
// FUNCTION: postTweet(userId, tweetId)
// ----------------------------------------------------------------------------------------------
//
// What it does:
// - Adds a new tweet for the given user
//
// How it works:
// - Pushes {globalTimestamp, tweetId} into the user's tweet heap
// - Increments globalTimestamp
//
// Why timestamp?
// - Tweet IDs do NOT guarantee recency
// - Timestamp ensures correct ordering across all users
//
// Time Complexity: O(log T), where T = tweets by the user
//
// ----------------------------------------------------------------------------------------------
// FUNCTION: getNewsFeed(userId)
// ----------------------------------------------------------------------------------------------
//
// Goal:
// - Return up to **10 most recent tweets** from:
//     → The user
//     → Users they follow
//
// IMPORTANT DESIGN RULE:
// - `getNewsFeed()` must be **read-only**
// - It should NOT permanently change stored tweets
//
// ----------------------------------------------------------------------------------------------
// STEP 1: Create a temporary max heap
// ----------------------------------------------------------------------------------------------
//
// priority_queue<pair<int,int>> mergedTweets
// - Temporarily holds tweets from user + followees
// - Ordered by timestamp automatically
//
// ----------------------------------------------------------------------------------------------
// STEP 2: Add user's own tweets
// ----------------------------------------------------------------------------------------------
//
// - Pop all tweets of the user
// - Push them into mergedTweets
// - Store them in a backup vector
// - Restore them back after processing
//
// Why backup?
// - Prevents permanent modification of stored data
//
// ----------------------------------------------------------------------------------------------
// STEP 3: Add followees' tweets
// ----------------------------------------------------------------------------------------------
//
// - Iterate over all followees of the user
// - For each followee:
//     → Pop all their tweets
//     → Push into mergedTweets
//     → Store in a backup vector
//     → Restore after processing
//
// This ensures:
// ✔ Tweets are visible only while followed
// ✔ Unfollow works correctly without cleanup
//
// ----------------------------------------------------------------------------------------------
// STEP 4: Extract top 10 tweets
// ----------------------------------------------------------------------------------------------
//
// - Pop at most 10 tweets from mergedTweets
// - Store only the tweetId in the result
// - Tweets are already ordered by recency
//
// ----------------------------------------------------------------------------------------------
// FUNCTION: follow(followerId, followeeId)
// ----------------------------------------------------------------------------------------------
//
// - Adds followeeId to followerId's follow set
// - Uses a set to avoid duplicates
//
// Time Complexity: O(1)
//
// ----------------------------------------------------------------------------------------------
// FUNCTION: unfollow(followerId, followeeId)
// ----------------------------------------------------------------------------------------------
//
// - Removes followeeId from followerId's follow set
// - Since tweets are not permanently merged, no cleanup is needed
//
// Time Complexity: O(1)
//
// ----------------------------------------------------------------------------------------------
// KEY TAKEAWAYS
// ----------------------------------------------------------------------------------------------
//
// ✔ Tweets are ordered by timestamp, not tweetId
// ✔ News feed generation is temporary and safe
// ✔ Unfollow automatically removes tweets from feed
// ✔ Easy to explain and logically clean
//
// ----------------------------------------------------------------------------------------------
// COMPLEXITY ANALYSIS
// ----------------------------------------------------------------------------------------------
//
// Time Complexity:
// - postTweet → O(log T)
// - getNewsFeed → O(total tweets of user + followees)
//
// Space Complexity:
// - O(total tweets) + temporary heap during feed generation
//
// ----------------------------------------------------------------------------------------------
// ONE-LINE INTERVIEW SUMMARY
// ----------------------------------------------------------------------------------------------
//
// “I store tweets per user using a max-heap with timestamps and generate the feed by temporarily
// merging tweets from the user and their followees, ensuring correctness and clean unfollow behavior.”
//
// ==============================================================================================
