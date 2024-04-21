const fs = require('fs');

fs.readFile("Streaming_History_Audio_2021-2022_0.json", "utf8", (err, data) => {
    if (err) {
        console.error(err);
        return;
    }
    data = JSON.parse(data);
    let playTime = [];
    for (i = 0; i < data.length; i++) {
        const song = data[i]["spotify_track_uri"];
        const song_name = data[i]["master_metadata_track_name"];
        const time = data[i]["ms_played"];
        timeS = time / 1000;

        try {
        const songExists = playTime.some(entry => entry.song === song);

        if (songExists) {
            const songEntry = playTime.find(entry => entry.song === song);
            songEntry.playtime += timeS;
        } else {
            playTime.push({ song: song, playtime: timeS , name: song_name});
        }

        } catch (error) {
            playTime.push({ song: song, playtime: timeS, name: song_name});
        }
    }
    fs.readFile('Streaming_History_Audio_2022_1.json', 'utf8', (err, data) => {
        if (err) {
            console.error(err);
            return;
        }
        data = JSON.parse(data);
        for (i = 0; i < data.length; i++) {
            const song = data[i]["spotify_track_uri"];
            const song_name = data[i]["master_metadata_track_name"];
            const time = data[i]["ms_played"];
            timeS = time / 1000;

            try {
            const songExists = playTime.some(entry => entry.song === song);

            if (songExists) {
                const songEntry = playTime.find(entry => entry.song === song);
                songEntry.playtime += timeS;
            } else {
                playTime.push({ song: song, playtime: timeS , name: song_name});
            }

            } catch (error) {
                playTime.push({ song: song, playtime: timeS, name: song_name});
            }
        }
        fs.readFile('Streaming_History_Audio_2022-2023_2.json', 'utf8', (err, data) => {
            if (err) {
                console.error(err);
                return;
            }
            data = JSON.parse(data);
            for (i = 0; i < data.length; i++) {
                const song = data[i]["spotify_track_uri"];
                const song_name = data[i]["master_metadata_track_name"];
                const time = data[i]["ms_played"];
                timeS = time / 1000;

                try {
                const songExists = playTime.some(entry => entry.song === song);

                if (songExists) {
                    const songEntry = playTime.find(entry => entry.song === song);
                    songEntry.playtime += timeS;
                } else {
                    playTime.push({ song: song, playtime: timeS , name: song_name});
                }

                } catch (error) {
                    playTime.push({ song: song, playtime: timeS, name: song_name});
                }
            }
            fs.readFile('Streaming_History_Audio_2023_3.json', 'utf8', (err, data) => {
                if (err) {
                    console.error(err);
                    return;
                }
                data = JSON.parse(data);
                for (i = 0; i < data.length; i++) {
                    const song = data[i]["spotify_track_uri"];
                    const song_name = data[i]["master_metadata_track_name"];
                    const time = data[i]["ms_played"];
                    timeS = time / 1000;

                    try {
                    const songExists = playTime.some(entry => entry.song === song);

                    if (songExists) {
                        const songEntry = playTime.find(entry => entry.song === song);
                        songEntry.playtime += timeS;
                    } else {
                        playTime.push({ song: song, playtime: timeS , name: song_name});
                    }

                    } catch (error) {
                        playTime.push({ song: song, playtime: timeS, name: song_name});
                    }
                }
                fs.readFile('Streaming_History_Audio_2023_4.json', 'utf8', (err, data) => {
                    if (err) {
                        console.error(err);
                        return;
                    }
                    data = JSON.parse(data);
                    for (i = 0; i < data.length; i++) {
                        const song = data[i]["spotify_track_uri"];
                        const song_name = data[i]["master_metadata_track_name"];
                        const time = data[i]["ms_played"];
                        timeS = time / 1000;
    
                        try {
                        const songExists = playTime.some(entry => entry.song === song);
    
                        if (songExists) {
                            const songEntry = playTime.find(entry => entry.song === song);
                            songEntry.playtime += timeS;
                        } else {
                            playTime.push({ song: song, playtime: timeS , name: song_name});
                        }
    
                        } catch (error) {
                            playTime.push({ song: song, playtime: timeS, name: song_name});
                        }
                    }
                    fs.readFile('Streaming_History_Audio_2023_5.json', 'utf8', (err, data) => {
                        if (err) {
                            console.error(err);
                            return;
                        }
                        data = JSON.parse(data);
                        for (i = 0; i < data.length; i++) {
                            const song = data[i]["spotify_track_uri"];
                            const song_name = data[i]["master_metadata_track_name"];
                            const time = data[i]["ms_played"];
                            timeS = time / 1000;
        
                            try {
                            const songExists = playTime.some(entry => entry.song === song);
        
                            if (songExists) {
                                const songEntry = playTime.find(entry => entry.song === song);
                                songEntry.playtime += timeS;
                            } else {
                                playTime.push({ song: song, playtime: timeS , name: song_name});
                            }
        
                            } catch (error) {
                                playTime.push({ song: song, playtime: timeS, name: song_name});
                            }
                        }
                        fs.readFile('Streaming_History_Audio_2023_6.json', 'utf8', (err, data) => {
                            if (err) {
                                console.error(err);
                                return;
                            }
                            data = JSON.parse(data);
                            for (i = 0; i < data.length; i++) {
                                const song = data[i]["spotify_track_uri"];
                                const song_name = data[i]["master_metadata_track_name"];
                                const time = data[i]["ms_played"];
                                timeS = time / 1000;
            
                                try {
                                const songExists = playTime.some(entry => entry.song === song);
            
                                if (songExists) {
                                    const songEntry = playTime.find(entry => entry.song === song);
                                    songEntry.playtime += timeS;
                                } else {
                                    playTime.push({ song: song, playtime: timeS , name: song_name});
                                }
            
                                } catch (error) {
                                    playTime.push({ song: song, playtime: timeS, name: song_name});
                                }
                            }
                            fs.readFile('Streaming_History_Audio_2023_7.json', 'utf8', (err, data) => {
                                if (err) {
                                    console.error(err);
                                    return;
                                }
                                data = JSON.parse(data);
                                for (i = 0; i < data.length; i++) {
                                    const song = data[i]["spotify_track_uri"];
                                    const song_name = data[i]["master_metadata_track_name"];
                                    const time = data[i]["ms_played"];
                                    timeS = time / 1000;
                
                                    try {
                                    const songExists = playTime.some(entry => entry.song === song);
                
                                    if (songExists) {
                                        const songEntry = playTime.find(entry => entry.song === song);
                                        songEntry.playtime += timeS;
                                    } else {
                                        playTime.push({ song: song, playtime: timeS , name: song_name});
                                    }
                
                                    } catch (error) {
                                        playTime.push({ song: song, playtime: timeS, name: song_name});
                                    }
                                }
                                fs.readFile('Streaming_History_Audio_2023_8.json', 'utf8', (err, data) => {
                                    if (err) {
                                        console.error(err);
                                        return;
                                    }
                                    data = JSON.parse(data);
                                    for (i = 0; i < data.length; i++) {
                                        const song = data[i]["spotify_track_uri"];
                                        const song_name = data[i]["master_metadata_track_name"];
                                        const time = data[i]["ms_played"];
                                        timeS = time / 1000;
                    
                                        try {
                                        const songExists = playTime.some(entry => entry.song === song);
                    
                                        if (songExists) {
                                            const songEntry = playTime.find(entry => entry.song === song);
                                            songEntry.playtime += timeS;
                                        } else {
                                            playTime.push({ song: song, playtime: timeS , name: song_name});
                                        }
                    
                                        } catch (error) {
                                            playTime.push({ song: song, playtime: timeS, name: song_name});
                                        }
                                    }
                                    fs.readFile('Streaming_History_Audio_2023-2024_9.json', 'utf8', (err, data) => {
                                        if (err) {
                                            console.error(err);
                                            return;
                                        }
                                        data = JSON.parse(data);
                                        for (i = 0; i < data.length; i++) {
                                            const song = data[i]["spotify_track_uri"];
                                            const song_name = data[i]["master_metadata_track_name"];
                                            const time = data[i]["ms_played"];
                                            timeS = time / 1000;
                        
                                            try {
                                            const songExists = playTime.some(entry => entry.song === song);
                        
                                            if (songExists) {
                                                const songEntry = playTime.find(entry => entry.song === song);
                                                songEntry.playtime += timeS;
                                            } else {
                                                playTime.push({ song: song, playtime: timeS , name: song_name});
                                            }
                        
                                            } catch (error) {
                                                playTime.push({ song: song, playtime: timeS, name: song_name});
                                            }
                                        }
                                        fs.readFile('Streaming_History_Audio_2024_10.json', 'utf8', (err, data) => {
                                            if (err) {
                                                console.error(err);
                                                return;
                                            }
                                            data = JSON.parse(data);
                                            for (i = 0; i < data.length; i++) {
                                                const song = data[i]["spotify_track_uri"];
                                                const song_name = data[i]["master_metadata_track_name"];
                                                const time = data[i]["ms_played"];
                                                timeS = time / 1000;
                            
                                                try {
                                                const songExists = playTime.some(entry => entry.song === song);
                            
                                                if (songExists) {
                                                    const songEntry = playTime.find(entry => entry.song === song);
                                                    songEntry.playtime += timeS;
                                                } else {
                                                    playTime.push({ song: song, playtime: timeS , name: song_name});
                                                }
                            
                                                } catch (error) {
                                                    playTime.push({ song: song, playtime: timeS, name: song_name});
                                                }
                                            }
                                            fs.readFile('Streaming_History_Audio_2024_11.json', 'utf8', (err, data) => {
                                                if (err) {
                                                    console.error(err);
                                                    return;
                                                }
                                                data = JSON.parse(data);
                                                for (i = 0; i < data.length; i++) {
                                                    const song = data[i]["spotify_track_uri"];
                                                    const song_name = data[i]["master_metadata_track_name"];
                                                    const time = data[i]["ms_played"];
                                                    timeS = time / 1000;
                                
                                                    try {
                                                    const songExists = playTime.some(entry => entry.song === song);
                                
                                                    if (songExists) {
                                                        const songEntry = playTime.find(entry => entry.song === song);
                                                        songEntry.playtime += timeS;
                                                    } else {
                                                        playTime.push({ song: song, playtime: timeS , name: song_name});
                                                    }
                                
                                                    } catch (error) {
                                                        playTime.push({ song: song, playtime: timeS, name: song_name});
                                                    }
                                                }
                                                playTime.sort((a, b) => b.playtime - a.playtime);
                                                playTime.slice(0, 100);
                                                playTime = JSON.stringify(playTime);
                                                fs.writeFile('playtime.json',(playTime), (err) => {
                                                    if (err) {
                                                        console.error(err);
                                                        return;
                                                    }
                                                    console.log("File has been created");
                                                });
                                            });
                                        });
                                    });
                                });
                            });
                        });
                    });
                });
            });
        })
    })      
});
