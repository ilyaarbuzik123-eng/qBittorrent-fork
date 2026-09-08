package com.yourname.qbittorrent

import android.os.Bundle
import android.widget.*
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    
    private lateinit var sessionPtr: Long
    private lateinit var wrapper: LibTorrentWrapper
    
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        
        wrapper = LibTorrentWrapper()
        sessionPtr = wrapper.createSession()
        
        val addButton = findViewById<Button>(R.id.addButton)
        val magnetInput = findViewById<EditText>(R.id.magnetInput)
        val statusText = findViewById<TextView>(R.id.statusText)
        
        addButton.setOnClickListener {
            val magnet = magnetInput.text.toString()
            if (magnet.isNotEmpty()) {
                wrapper.addTorrent(sessionPtr, magnet)
                statusText.text = "Добавлено: $magnet"
            }
        }
    }
}
