package main

import (
	"fmt"
)


/*
The commented statements in the functions can be used to 
see the execution flow. It'll print the values of the 
attributes/variables that controls the flow of the execution.
*/


type Link struct {
	prevKey int
	nextKey int
}


type LRUCache struct {
	Capacity int
    ItemsCount int
	LatestKeyAccessed int
	OldestKeyAccessed int
	CacheKeyTracker map[int]*Link
	Store map[int]int
}


func Constructor(capacity int) LRUCache {
    return LRUCache {
		Capacity: capacity,
		ItemsCount: 0,
		LatestKeyAccessed: -1,
		OldestKeyAccessed: -1,
		CacheKeyTracker: make(map[int]*Link),
		Store: make(map[int]int),
	}
}


func (this *LRUCache) Get(key int) int {
	// fmt.Println("----------")
	// for key, value := range this.CacheKeyTracker {
	// 	fmt.Println("key:", key, ", prevKey:", value.prevKey, ", nextKey:", value.nextKey)
	// }
	// fmt.Println("OldestKeyAccessed:", this.OldestKeyAccessed)
	// fmt.Println("----------")
	// fmt.Println("Get -->", key)
	value, found := this.Store[key]
    if found {
		var prev int = this.CacheKeyTracker[key].prevKey
		var next int = this.CacheKeyTracker[key].nextKey
		if prev != -1 && next != -1 {
			this.CacheKeyTracker[prev].nextKey = next
			this.CacheKeyTracker[next].prevKey = prev
			this.CacheKeyTracker[this.LatestKeyAccessed].nextKey = key
			this.CacheKeyTracker[key].prevKey = this.LatestKeyAccessed
			this.CacheKeyTracker[key].nextKey = -1
		} else if prev == -1 && next != -1 {
			this.CacheKeyTracker[next].prevKey = -1
			this.CacheKeyTracker[this.LatestKeyAccessed].nextKey = key
			this.CacheKeyTracker[key].prevKey = this.LatestKeyAccessed
			this.CacheKeyTracker[key].nextKey = -1
			this.OldestKeyAccessed = next
		}
		this.LatestKeyAccessed = key
		
		// fmt.Println("Get --> OldestKeyAccessed:", this.OldestKeyAccessed)
		// fmt.Println("Get --> LatestKeyAccessed:", this.LatestKeyAccessed)
		// fmt.Println(value)
		// fmt.Println()
		return value
	} else {
		// fmt.Println("Get --> OldestKeyAccessed:", this.OldestKeyAccessed)
		// fmt.Println("Get --> LatestKeyAccessed:", this.LatestKeyAccessed)
		// fmt.Println(-1)
		// fmt.Println()
		return -1
	}
}

func (this *LRUCache) Put(key int, value int)  {
	// fmt.Println("----------")
	// for key, value := range this.CacheKeyTracker {
	// 	fmt.Println("key:", key, ", prevKey:", value.prevKey, ", nextKey:", value.nextKey)
	// }
	// fmt.Println("OldestKeyAccessed:", this.OldestKeyAccessed)
	// fmt.Println("----------")
	// fmt.Println("Put -->", key, value)
	_, found := this.CacheKeyTracker[key]
    if found {
		var prev int = this.CacheKeyTracker[key].prevKey
		var next int = this.CacheKeyTracker[key].nextKey
		if prev != -1 && next != -1 {
			this.CacheKeyTracker[prev].nextKey = next
			this.CacheKeyTracker[next].prevKey = prev
			this.CacheKeyTracker[this.LatestKeyAccessed].nextKey = key
			this.CacheKeyTracker[key].prevKey = this.LatestKeyAccessed
			this.CacheKeyTracker[key].nextKey = -1
		} else if prev == -1 && next != -1 {
			this.CacheKeyTracker[next].prevKey = -1
			this.CacheKeyTracker[this.LatestKeyAccessed].nextKey = key
			this.CacheKeyTracker[key].prevKey = this.LatestKeyAccessed
			this.CacheKeyTracker[key].nextKey = -1
			this.OldestKeyAccessed = next
		}
		this.LatestKeyAccessed = key
		this.Store[key] = value
	} else {  // // When the key is not found
		// When the key is not found and the `Store` has "capacity" left
		if this.ItemsCount < this.Capacity {
			if this.ItemsCount == 0 {
				link := Link{prevKey: -1, nextKey: -1}
				this.CacheKeyTracker[key] = &link
				this.OldestKeyAccessed = key
			} else {
				this.CacheKeyTracker[this.LatestKeyAccessed].nextKey = key
				link := Link{prevKey: this.LatestKeyAccessed, nextKey: -1}
				this.CacheKeyTracker[key] = &link
			}
			this.LatestKeyAccessed = key
			this.Store[key] = value
			this.ItemsCount ++
		} else {  // When the key is not found and the `Store` is full
			var next int = this.CacheKeyTracker[this.OldestKeyAccessed].nextKey
			if next == -1 {
				link := Link{prevKey: -1, nextKey: -1}
				this.CacheKeyTracker[key] = &link
				delete(this.CacheKeyTracker, this.OldestKeyAccessed)
				delete(this.Store, this.OldestKeyAccessed)
				this.OldestKeyAccessed = key
			} else {
				this.CacheKeyTracker[next].prevKey = -1
				delete(this.CacheKeyTracker, this.OldestKeyAccessed)
				delete(this.Store, this.OldestKeyAccessed)
				this.CacheKeyTracker[this.LatestKeyAccessed].nextKey = key
				link := Link{prevKey: this.LatestKeyAccessed, nextKey: -1}
				this.CacheKeyTracker[key]= &link
				this.OldestKeyAccessed = next
			}
			this.LatestKeyAccessed = key
			this.Store[key] = value
		}
	}
	// fmt.Println("Put --> OldestKeyAccessed:", this.OldestKeyAccessed)
	// fmt.Println("Put --> LatestKeyAccessed:", this.LatestKeyAccessed)
	// fmt.Println()
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(Capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value); 
 */
 func main() {
	// lruCache := Constructor(2)
	// lruCache.Put(2, 1)
	// lruCache.Put(1, 1)
	// lruCache.Put(2, 3)
	// lruCache.Put(4, 1)
	// lruCache.Get(1)
	// lruCache.Get(2)

	lruCache := Constructor(2)
	lruCache.Get(2)
	lruCache.Put(2, 6)
	lruCache.Get(1)
	lruCache.Put(1, 5)
	lruCache.Put(1, 2)
	lruCache.Get(1)
	lruCache.Get(2)
}
